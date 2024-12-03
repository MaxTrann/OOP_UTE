#pragma once
#include <string>
#include <vector>
#include "Transaction.h"
#include "Loan_Borrow.h"
#include "Transaction.h"
#include "DateTime.h"
#include "masked_password.h"
using namespace std;
class Account{
    private:
        string acountID; // sửa chỗ nào thành string 
        string accountName;
        string pasword;
        double balance;
        vector <Transaction> historyTrans;
        vector <Loan_Borrow> listLoan_Borrow;
    public:
        bool login(string name)
        {
            if(name == this->accountName)
                return true;
            else
                return false;
        }
        void updateName(string newName)
        {
            this->accountName = newName;
        }
        void updateID(string newID){
            this->acountID = newID;
        }
        void updateBalance(double newBalance){
            this->balance = newBalance;
        }
        void updatePassword(string newPassWord)
        {
            this->pasword = newPassWord;
        }
        double getBalance()
        {
            return this->balance;
        }
        string getNameAcount()
        {
            return this->accountName;
        }
        vector <Transaction> &getTransaction()
        {
            return this->historyTrans;
        }
        vector <Loan_Borrow> &getLoan_Borrow()
        {
            return this->listLoan_Borrow;
        }
        bool checkPassWord(string password)
        {
            return this->pasword == password;
        }
        void input()
        {
            cout << "Nhap ID tai khoan: "; getline(cin, this->acountID);
            cout << "Nhap ten tai khoan: "; getline(cin, this->accountName);
            cout << "Nhap mat khau: "; this->pasword = getMaskedPassword();
            cout << "Nhap so du tai khoan: "; cin >> this->balance;
        }
        void inputTransfer(){
            cout << "Nhap ID tai khoan: "; getline(cin, this->acountID);
            cout << "Nhap ten tai khoan: "; getline(cin, this->accountName);
        }
        void makeTrans()
        {
            Transaction x;
            x.input();
            if(x.getAmount() > this->balance)
            {
                cout << "So du khong du de thuc hien giao dich" << endl;
                return;
            }
            this->historyTrans.push_back(x);
            this->balance -= x.getAmount();
        }
        void makeLoan_Borrow(Loan_Borrow x)
        {
            if(x.getType() == 0 && x.getAmount() > this->balance)
            {
                cout << "So du khong du de thuc hien giao dich !" << endl;
                return;
            }
            this->listLoan_Borrow.push_back(x);
            if(x.getType() == 0)
                this->balance -= x.getAmount();
            else if(x.getType() == 1)
                this->balance += x.getAmount();
        }
        void display()
        {
            cout << "ID tai khoan: " << this->acountID << endl;
            cout << "Ten tai khoan: " << this->accountName << endl;
            cout << "So du tai khoan: " << fixed << setprecision(2) << this->balance << endl;
        }
        void displayTransfer(){
            cout << "ID tai khoan: " << this->acountID << endl;
            cout << "Ten tai khoan: " << this->accountName << endl;
        }
        void deleteTrans()
        {
            if(this->historyTrans.empty())
                cout << this->accountName << " : giao dich rong";
            this->historyTrans.clear();
        }
        void deleteLoan()
        {
            if(this->listLoan_Borrow.empty())
                cout << this->accountName << " : khong ton tai khoan vay";
            for(int i = 0; i < this->listLoan_Borrow.size(); i++)
            {
                if(this->listLoan_Borrow[i].getType() == 0 && this->listLoan_Borrow[i].getStatus() == true)
                    this->listLoan_Borrow.erase(this->listLoan_Borrow.begin() + i);
            }
        }
        void deleteBorrow()
        {
            if(this->listLoan_Borrow.empty())
                cout << this->accountName << " : khong ton tai khoan vay";
            for(int i = 0; i < this->listLoan_Borrow.size(); i++)
            {
                if(this->listLoan_Borrow[i].getType() == 1 && this->listLoan_Borrow[i].getStatus() == true)
                    this->listLoan_Borrow.erase(this->listLoan_Borrow.begin() + i);
            }
        }
};

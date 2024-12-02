#pragma once
#include <iostream>
#include <string>
#include "DateTime.h"
using namespace std;
class Transaction{
    protected:
        string transID;
        double amount;
        DateTime Date;
        bool statusTrans;
        string typeTrans;
    public:
        virtual void input()
        {
            cin.ignore();
            cout << "Nhap ID giao dich: ";  getline(cin, this->transID);
            cout << "Nhap so tien giao dich: "; cin >> this->amount;
            cout << "Nhap thoi gian giao dich: " << endl;
            this->Date.input();
            this->statusTrans = true; // mac dinh giao dich luon thanh cong
            cin.ignore();
            cout << "Nhap loai giao dich: ";    getline(cin, this->typeTrans);
        }
        virtual void inputLoanBorrow()
        {
            cin.ignore();
            cout << "Nhap ID giao dich: ";  getline(cin, this->transID);
            cout << "Nhap so tien giao dich: "; cin >> this->amount;
            cout << "Nhap thoi gian giao dich: " << endl;
            this->Date.input();
            this->statusTrans = true; // mac dinh giao dich luon thanh cong
        }
        void updateAmount(double newAmount)
        {
            this->amount = newAmount;
        }
        void updateStatusTrans()
        {
            this->statusTrans = ! this->statusTrans;
        }
        void updateTypeTrans(string newTypeTrans)
        {
            this->typeTrans = newTypeTrans;
        }
        double getAmount()
        {
            return this->amount;
        }
        string getTransID()
        {
            return this->transID;
        }
        virtual void display()
        {
            cout << "Thong tin giao dich: \n";
            cout << "ID giao dich: " << this->transID << endl;
            cout << "So tien giao dich: " << this->amount << endl;
            cout << "Thoi gian giao dich: "; this->Date.display();
            cout << "Trang thai giao dich: " << (this->statusTrans ? "Thanh cong" : "Chua thanh cong") << endl;
            cout << "Loai giao dich: " << this->typeTrans << endl;
        }
        virtual void displayLoanBorrow(){
            cout << "Thong tin giao dich: \n";
            cout << "ID giao dich: " << this->transID << endl;
            cout << "So tien giao dich: " << fixed << setprecision(2) << this->amount << endl;
            cout << "Thoi gian giao dich: "; this->Date.display();
            cout << "Trang thai giao dich: " << (this->statusTrans ? "Thanh cong" : "Chua thanh cong") << endl;
        }
};
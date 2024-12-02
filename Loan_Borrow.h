#pragma once
#include <string>
#include "Transaction.h"
#include "DateTime.h"
using namespace std;
class Loan_Borrow : public Transaction{
    private:
        string name;
        double interestRate;
        DateTime endDate;
        bool status; // tra xong chua hoac nhan du chua
        bool type; // vay hay muon 
    public:
        void input() override{
            Transaction :: inputLoanBorrow();
            cin.ignore();
            cout << "Nhap ten nguoi vay/muon: "; getline(cin, this->name);
            cout << "Nhap lai suat: "; cin >> this->interestRate;
            cout << "Nhap thoi gian hoan thanh vay/muon: " << endl;; // hạn để trả hoặc nhận
            this->endDate.input();
            this->status = false; // mac  dinh la chua hoan thanh
            cout << "Nhap loai giao dich (0: vay, 1: muon): "; cin >> this->type;
        }
        void notification()
        {
            if(this->status == true) 
                cout << "Da hoan tra thanh cong giao dich !" << endl;
            else 
                cout << "Chua hoan tra giao dich" << endl;
        }
        void updateStatus()
        {
            this->status = !this->status;
        }
        void updateInterestRate(double newInterestRate)
        {
            this->interestRate = newInterestRate;
        }
        void updateEndDate()
        {
            cout << "Nhap lai thoi gian" << endl;
            this->endDate.input();
        }
        double getData()
        {
            return this->amount * (this->interestRate / 100) + this->amount;
        }
        bool getType()
        {
            return this->type;
        }
        bool getStatus()
        {
            return this->status;
        }
        void setType(int x)
        {
            this->type = x;
        }
        void display() override{
            Transaction::displayLoanBorrow();
            cout << "Ten nguoi vay/ muon: " << this->name << endl;
            cout << "Lai suat: " << this->interestRate << " %" << endl;
            cout << "Thoi gian den han: "; this->endDate.display();
            cout << "Trang thai vay/muon: "; this->notification();
            cout << "Loai giao dich: "; this->type == 0 ? cout << "Vay" << endl : cout << "Muon" << endl;
            cout << "So tien "; this->type == 0 ? cout << "can tra la: " : cout << " nhan duoc la: ";
            cout << fixed << setprecision(2) << this->getData()<< " VND"<< endl;
        }
};
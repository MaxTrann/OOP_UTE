#pragma once
#include "Transaction.h"
#include "Account.h"
#include <iostream>
using namespace std;
class Transfer : public Transaction{
    private:
        Account accountSend;
        Account accountRecieve;
    public:
        void input() override
        {
            cout << "Nhap tai khoan gui: " << endl;
            this->accountSend.inputTransfer();
            cout << "Nhap tai khoan nhan: " << endl;
            this->accountRecieve.inputTransfer();
            cout << "Nhap thong tin giao dich: " << endl;
            Transaction :: input();
        }
        void display () override
        {
            cout << "Tai khoan gui: " << endl;
            this->accountSend.displayTransfer();
            cout << "Tai khoan nhan: " << endl;
            this->accountRecieve.displayTransfer();
            Transaction :: display();
        }

};
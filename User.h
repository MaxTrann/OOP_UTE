#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include "Account.h"
#include "Loan_Borrow.h"
#include "Transaction.h"
#include "Transfer.h"
#include "masked_password.h"
using namespace std;
class User {
    private:
        string userID; //CCCD
        string name;
        string email;
        string password;
        string sdt;
        double cash;
        vector <Account> account;
        vector <Transaction> transactionCash;
    public:
        void input()
        {
            cout << "Nhap User ID: ";  getline(cin, this->userID);
            cout << "Nhap ten User: ";  getline(cin, this->name);
            cout << "Nhap Email: "; getline(cin, this->email);
            cout << "Nhap Password: "; this->password = getMaskedPassword();
            cout << "Nhap SDT: "; getline(cin, this->sdt);
            cout << "Nhap so luong tien mat: "; cin >> this->cash;
        }
        void addAcount()
        {
            Account newAcount;
            while(true) {
                newAcount.input();
                bool flag = true;
                for(int i = 0; i < this->account.size(); i++)
                {
                    if(newAcount.getAccountID() == this->account[i].getAccountID())
                    {
                        cout << "ID tai khoan da ton tai, vui long nhap lai!" << endl;
                        flag = false;
                        break;
                    }
                    if(this->account[i].getNameAcount() == newAcount.getNameAcount())
                    {
                        cout << "Ten tai khoan da ton tai, vui long nhap lai!" << endl;
                        flag = false;
                        break;
                    }
                }
                if(flag == true) break;
            }
            account.push_back(newAcount);
            cout << "Tai khoan moi da duoc them vao." << endl;
        }   
        void display()
        {
            // Kiểm tra xem thông tin người dùng đã được nhập hay chưa
            if (this->name.empty() || this->email.empty() || this->password.empty() || this->userID.empty()) {
                cout << "Chua co thong tin nguoi dung. Vui long nhap thong tin truoc!" << endl;
                return;
            }
            cout << "User ID: " << this->userID << endl;
            cout << "Ten user: " << this->name << endl;
            cout << "Email user: " << this->email << endl;
            cout << "So dien thoai user: " << this->sdt << endl;
        }
        void displayBalanceInfo() {
            double balanceCash = this->getBalanceCash(); // Số dư tiền mặt
            double balanceTotal = this->getBalanceCashVirtual(); // Tổng số dư (tiền mặt + tài khoản)

            cout << "\n================== Thong Tin So Du ==================" << endl;
            cout << "So du tien mat: " << fixed << setprecision(2) << balanceCash << " VND" << endl;
            cout << "Tong so du (tien mat + tai khoan): " << fixed << setprecision(2) << balanceTotal << " VND" << endl;
            cout << "=====================================================" << endl;
        }
        void displayAllAccountBalances() {
            if (this->account.empty()) {
                cout << "Khong co tai khoan nao!" << endl;
                return;
            }

            for (int i = 0; i < this->account.size(); i++) {
                cout << "\nTai khoan " << i + 1 << ":" << endl;
                cout << "\tTen tai khoan: " << this->account[i].getNameAcount() << endl;
                cout << "\tSo du hien tai: " << fixed << setprecision(2) 
                    << this->account[i].getBalance() << " VND" << endl;
                cout << "----------------------------------------------------------" << endl;
            }
            cout << "==========================================================" << endl;
        }

        void showAccount()
        {
            for(Account acc : this->account)
            {
                cout << "Ten tai khoan: " << acc.getNameAcount() << endl;
            }
        }
        void deleteAcount()
        {
            string name;
            bool check = true;
            cout << "Nhap ten tai khoan muon xoa: ";
            cin.ignore();
            getline(cin, name);
            for(int i = 0; i < this->account.size(); i++)
            {
                if(this->account[i].getNameAcount() == name)
                {
                    check = false;
                    cout << "Nhap mat khau tai khoan: ";
                    string passWord = getMaskedPassword();
                    if(this->account[i].checkPassWord(passWord) == true)
                    {
                        this->account.erase(this->account.begin() + i);
                    }
                    else
                    {
                        cout << "Mat khau sai ! khong the xoa tai khoan !" << endl;
                    }
                }
            }
            if(check == true)
            {
                cout << "Ten tai khoan khong ton tai !";
            }
        }
        void updateAccount()
        {
            cout << "Nhap ten tai khoan muon sua: ";
            string name; getline(cin, name);
            for(int i = 0; i < this->account.size(); i++)
            {
                if(this->account[i].getNameAcount() == name)
                {
                    cout << "Nhap mat khau de xac minh: ";
                    string checkpass = getMaskedPassword();
                    int count = 0;
                    while(this->account[i].checkPassWord(checkpass) == false)
                    {
                        if(count == 5)  return;
                        cout << "Mat khau khong chinh xac (con " << 5 - count << "lan nhap)" << endl;
                        cout << "Vui long nhap lai mat khau: ";
                        checkpass = getMaskedPassword();
                        count ++;
                    }
                    cout << "1. Ten tai khoan" << endl;
                    cout << "2. Mat khau tai khoan" << endl;
                    cout << "3. So du tai khoan" << endl;
                    cout << "Chon thong tin muon sua doi: ";
                    int choice; cin >> choice;
                    if(choice == 1)
                    {
                        string newName;
                        while(true){
                            bool flag = true;
                            cout << "Nhap ten tai khoan moi: ";
                            cin.ignore();
                            getline(cin, newName);
                            for(int i = 0; i < this->account.size(); i++)
                            {
                                if(this->account[i].getNameAcount() == newName)
                                {
                                    cout << "Ten tai khoan da ton tai ! vui long nhap lai";
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag == true) break;
                        }
                        this->account[i].updateName(newName);
                    }
                    else if(choice == 2)
                    {
                        cout << "Nhap mat khau moi: ";
                        string newPassWord;
                        cin.ignore();
                        newPassWord = getMaskedPassword();
                        this->account[i].updatePassword(newPassWord);
                    }
                    else if (choice == 3)
                    {
                        cout << "Nhap so du moi: ";
                        double newBalance;
                        cin >> newBalance;
                        this->account[i].updateBalance(newBalance);
                    }
                    else 
                    {
                        cout << "Lua chon khong hop le !" << endl;
                    }
                }
            }
        }
        void addTransaction()
        {
            cout << "1. Giao dich bang tai khoan tien mat" << endl;
            cout << "2. Giao dich bang tai khoan khac" << endl;
            cout << "Chon loai giao dich: ";
            int choice; cin >> choice;

            do{
                if (choice != 1 && choice != 2){
                    cout << "Lua chon khong hop le! Vui long nhap lai!\n";
                    cout << "Chon loai giao dich: "; cin >> choice;
                }
            }while(choice != 1 && choice != 2);

            if(choice == 1)
            {
                Transaction x;
                cin.ignore();
                x.input();
                while(x.getAmount() > this->cash)
                {
                    cout << "So tien mat khong du de giao dich ! Vui long nhap lai giao dich" << endl;
                    x.input();
                }
                this->cash -= x.getAmount();
                this->transactionCash.push_back(x);
            }
            else if(choice == 2)
            {
                cout << "Nhap ten tai khoan: ";
                string nameAcc; 
                cin.ignore();
                getline(cin, nameAcc);
                bool flag = true;
                for(int i = 0; i < this->account.size(); i++)
                {
                    if(this->account[i].getNameAcount() == nameAcc)
                    {
                        flag = false;
                        cout << "Nhap mat khau: ";
                        string passWord;
                        passWord = getMaskedPassword();
                        int count = 0;
                        while(this->account[i].checkPassWord(passWord) == false)
                        {
                            if(count == 5)  return;
                            cout << "Mat khau khong chinh xac (con " << 5 - count << "lan nhap)" << endl;
                            cout << "Vui long nhap lai mat khau: ";
                            passWord = getMaskedPassword();
                            count ++;
                        }
                        this->account[i].makeTrans();
                    }
                }
                if(flag == true) cout << "Ten tai khoan khong ton tai !" << endl;
            }

        }
        void deleteTransaction()
        {
            if(this->transactionCash.empty())
                cout << "Giao dich bang tien mat rong" << endl;
            for(int i = 0; i < this->transactionCash.size(); i++)
            {
                if(this->transactionCash[i].getStatus() == true)
                    this->transactionCash.erase(this->transactionCash.begin() + i);
            }
            if(this->account.empty())
                cout << "Khong ton tai tai khoan" << endl;
            for(int i = 0; i < this->account.size(); i++)
            {
                this->account[i].deleteTrans();
            }
            cout << "Da xoa thanh cong giao dich !" << endl;
        }
        void updateTransaction() {
            cout << "Nhap ID giao dich muon cap nhat: ";
            string transID;
            cin >> transID;
            for (auto& trans : transactionCash) {
                if (trans.getTransID() == transID) {
                    cout << "Giao dich tim thay:\n";
                    trans.display();

                    cout << "Chon thong tin can cap nhat:\n";
                    cout << "1. So tien\n";
                    cout << "2. Noi dung giao dich\n";
                    cout << "3. Trang thai giao dich\n";
                    cout << "Lua chon cua ban: ";
                    int choice;
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            cout << "Nhap so tien moi: ";
                            double newAmount;
                            cin >> newAmount;
                            trans.updateAmount(newAmount);
                            cout << "Cap nhat thanh cong so tien.\n";
                            break;
                        }
                        case 2: {
                            cout << "Nhap noi dung giao dich moi: ";
                            string newType;
                            cin.ignore();
                            getline(cin, newType);
                            trans.updateTypeTrans(newType);
                            cout << "Cap nhat thanh cong noi dung giao giao dich.\n";
                            break;
                        }
                        case 3: {
                            trans.updateStatusTrans();
                            cout << "Cap nhat trang thai giao dich thanh cong.\n";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le.\n";
                    }
                    return;
                }
            }

            for (auto& acc : account) {
                auto& transactions = acc.getTransaction();
                for (auto& trans : transactions) {
                    if (trans.getTransID() == transID) {
                        cout << "Giao dich tim thay trong tai khoan:\n";
                        trans.display();

                        cout << "Chon thong tin can cap nhat:\n";
                        cout << "1. So tien\n";
                        cout << "2. Noi dung giao dich\n";
                        cout << "3. Trang thai giao dich\n";
                        cout << "Lua chon cua ban: ";
                        int choice;
                        cin >> choice;

                        switch (choice) {
                            case 1: {
                                cout << "Nhap so tien moi: ";
                                double newAmount;
                                cin >> newAmount;
                                trans.updateAmount(newAmount);
                                cout << "Cap nhat thanh cong so tien.\n";
                                break;
                            }
                            case 2: {
                                cout << "Nhap noi dung giao dich moi: ";
                                string newType;
                                cin.ignore();
                                getline(cin, newType);
                                trans.updateTypeTrans(newType);
                                cout << "Cap nhat thanh cong noi dung giao dich.\n";
                                break;
                            }
                            case 3: {
                                trans.updateStatusTrans();
                                cout << "Cap nhat trang thai giao dich thanh cong.\n";
                                break;
                            }
                            default:
                                cout << "Lua chon khong hop le.\n";
                        }
                        return;
                    }
                }
            }

            cout << "Khong tim thay giao dich voi ID da nhap.\n";
        }

        double getBalanceCash()
        {
            double result = this->cash;
            return result;
        }
        double getBalanceCashVirtual()
        {
            double result = this->cash;
            for(int i = 0; i < this->account.size(); i++)
            {
                result += this->account[i].getBalance();
            }
            return result;
        }
        void transactionHistory()
        {
            cout << "-->Cac giao dich tien mat: " << endl;
            for(int i = 0;i < this->transactionCash.size(); i++)
            {
                this->transactionCash[i].display();
            }
            cout << "-->Cac giao dich bang tai khoan: " << endl;
            for(int i = 0; i < this->account.size(); i++)
            {
                cout << "Giao dich cua tai khoan: " << this->account[i].getNameAcount() << endl;
                for(int j = 0; j < this->account[i].getTransaction().size(); j++)
                {
                    this->account[i].getTransaction()[j].display();
                }
            }
        }
        void addLoan()
        {
            cout << "Nhap ten tai khoan: ";
            cin.ignore();
            string name; getline(cin, name);
            bool check = true;
            for(int i = 0; i < this->account.size(); i++)
            {
                if(this->account[i].login(name) == true)
                {
                    check = false;
                    cout << "Nhap mat khau: ";
                    string pass = getMaskedPassword();
                    int count = 0;
                    while(this->account[i].checkPassWord(pass) == false)
                    {
                        if(count == 5)  return;
                        cout << "Mat khau khong chinh xac (con " << 5 - count << " lan nhap)" << endl;
                        cout << "Vui long nhap lai mat khau: ";
                        pass = getMaskedPassword();
                        count ++;
                    }
                    Loan_Borrow x;
                    x.input();
                    x.setType(0);
                    this->account[i].makeLoan_Borrow(x);
                }
            }
            if(check == true)   cout << "Ten tai khoan khong ton tai !" << endl; 
        }
        void updateLoan()
        {
            cout << "Nhap ID khoan vay/muon muon cap nhat: ";
            string loanID;
            cin >> loanID;
            for (auto& acc : account) {
                auto &loans = acc.getLoan_Borrow();
                for (auto& loan : loans) {
                    if (loan.getTransID() == loanID && loan.getType() == 0) {
                        cout << "Khoan vay/muon tim thay\n";
                        loan.display();
                        cout << "Chon thong tin can cap nhat:\n";
                        cout << "1. So tien vay/muon\n";
                        cout << "2. Lai suat\n";
                        cout << "3. Ngay het han\n";
                        cout << "4. Trang thai (Chua thanh toan / Da thanh toan)\n";
                        cout << "Lua chon cua ban: ";
                        int choice;
                        cin >> choice;
                        switch (choice) {
                            case 1: {
                                cout << "Nhap so tien moi: ";
                                double newAmount;
                                cin >> newAmount;
                                loan.updateAmount(newAmount);
                                cout << "Cap nhat thanh cong so tien vay/muon.\n";
                                break;
                            }
                            case 2: {
                                cout << "Nhap lai suat moi: ";
                                double newInterestRate;
                                cin >> newInterestRate;
                                loan.updateInterestRate(newInterestRate);
                                cout << "Cap nhat thanh cong lai suat.\n";
                                break;
                            }
                            case 3: {
                                cout << "Nhap ngay het han moi:\n";
                                loan.updateEndDate();
                                cout << "Cap nhat thanh cong ngay het han.\n";
                                break;
                            }
                            case 4: {
                                loan.updateStatus();
                                cout << "Cap nhat trang thai giao dich thanh cong.\n";
                                break;
                            }
                            default:
                                cout << "Lua chon khong hop le.\n";
                        }
                        return;
                    }
                }
            }
        cout << "Khong tim thay khoan vay/muon voi ID da nhap.\n";
        }
        void deleteLoan()
        {
            if(this->account.empty())
                cout << "Khong ton tai tai khoan" << endl;
            for(int i = 0; i < this->account.size(); i++)
                this->account[i].deleteLoan();
            cout << "Da xoa thanh cong cac khoan vay da duoc hoan tra day du !" << endl;
        }
        void loanHistory()
        {
            for(int i = 0; i < this->account.size(); i++)
            {
                for(int j = 0; j < this->account[i].getLoan_Borrow().size(); j ++)
                {
                    if(this->account[i].getLoan_Borrow()[j].getType() == 0)
                    {
                        this->account[i].getLoan_Borrow()[j].display();
                    }
                }
            }
        }
        void addBorrow()
        {
            cout << "Nhap ten tai khoan: ";
            string name;
            cin.ignore();
            getline(cin, name);
            bool check = true;
            for(int i = 0; i < this->account.size(); i++)
            {
                if(this->account[i].login(name) == true)
                {
                    check = false;
                    cout << "Nhap mat khau: ";
                    string pass = getMaskedPassword();
                    int count = 0;
                    while(this->account[i].checkPassWord(pass) == false)
                    {
                        if(count == 5)  return;
                        cout << "Mat khau khong chinh xac (con " << 5 - count << "lan nhap)" << endl;
                        cout << "Vui long nhap lai mat khau: ";
                        getline(cin, pass);
                        count ++;
                    }
                    Loan_Borrow x;
                    x.input();
                    x.setType(1);
                    this->account[i].makeLoan_Borrow(x);
                }
            }
            if(check == true)   cout << "Ten tai khoan khong ton tai !" << endl; 
        }
        void updateBorow()
        {
            cout << "Nhap ID khoan vay/muon muon cap nhat: ";
            string BorrowID; cin >> BorrowID;
            for(auto &acc : account)
            {
                auto &borrows = acc.getLoan_Borrow();
                for(auto &borrow : borrows)
                {
                    if(borrow.getTransID() == BorrowID && borrow.getType() == 1)
                    {
                        cout << "Khoan vay/muon tim thay" << endl;
                        borrow.display();
                        cout << "Chon thong tin can cap nhat:\n";
                        cout << "1. So tien vay/muon\n";
                        cout << "2. Lai suat\n";
                        cout << "3. Ngay het han\n";
                        cout << "4. Trang thai (Chua thanh toan / Da thanh toan)\n";
                        cout << "Lua chon cua ban: ";
                        int choice;
                        cin >> choice;
                        switch (choice) {
                            case 1: {
                                cout << "Nhap so tien moi: ";
                                double newAmount;
                                cin >> newAmount;
                                borrow.updateAmount(newAmount);
                                cout << "Cap nhat thanh cong so tien vay/muon.\n";
                                break;
                            }
                            case 2: {
                                cout << "Nhap lai suat moi: ";
                                double newInterestRate;
                                cin >> newInterestRate;
                                borrow.updateInterestRate(newInterestRate);
                                cout << "Cap nhat thanh cong lai suat.\n";
                                break;
                            }
                            case 3: {
                                cout << "Nhap ngay het han moi:\n";
                                borrow.updateEndDate();
                                cout << "Cap nhat thanh cong ngay het han.\n";
                                break;
                            }
                            case 4: {
                                borrow.updateStatus();
                                cout << "Cap nhat trang thai giao dich thanh cong.\n";
                                break;
                            }
                            default:
                                cout << "Lua chon khong hop le.\n";
                        }
                        return;
                    }
                }
            }
        cout << "Khong tim thay khoan vay/muon voi ID da nhap.\n";  
        }
        void deleteBorrow()
        {
            if (this->account.empty())
                cout << "Khong ton tai tai khoan" << endl;
            for (int i = 0; i < this->account.size(); i++)
                this->account[i].deleteBorrow();
            cout << "Da xoa thanh cong cac khoan muon da hoan tra day du" << endl;
        }
        void borrowHistory()
        {
            for(int i = 0; i < this->account.size(); i++)
            {
                for(int j = 0; j < this->account[i].getLoan_Borrow().size(); j ++)
                {
                    if(this->account[i].getLoan_Borrow()[j].getType() == 1)
                    {
                        this->account[i].getLoan_Borrow()[j].display();
                    }
                }
            }
        }
        void reportAccount()
        {
            if(this->account.empty())
                cout << "Khong ton tai tai khoan" << endl;
            cout << "Thong tin cac tai khoan da duoc them: " << endl;
            for(int i = 0; i < this->account.size(); i++)
                this->account[i].display();
        }
        void reportLoan_Borrow()
        {
            cout << "Thong tin khoan vay/ muon: " << endl;
            for(int i = 0; i < this->account.size(); i++)
            {
                for(int j = 0; j < this->account[i].getLoan_Borrow().size(); j++)
                    this->account[i].getLoan_Borrow()[j].display();
            }
        }
};

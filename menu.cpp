#include <iostream>
#include "User.h"

using namespace std;

// Ham hien thi menu
void showMenu() 
{
    cout <<"\n\t\t\t+----------------------------MENU WINDOW-----------------------------+";
    cout <<"\n\t\t\t|                                                                    |";
    cout <<"\n\t\t\t| 0. Exit Program                       2. Transaction Option Window |";
    cout <<"\n\t\t\t| 1. Account Option Window              3. Report Option Window      |";
    cout <<"\n\t\t\t|____________________________________________________________________|" << endl;
    cout << "\nChon thao tac: ";
}

int main() 
{
    User user;
    int choice;
    cout << "\n\t\t\t=======================LOGIN======================" << endl;
    cout << "\t\t\t|      VUI LONG NHAP NGUOI DUNG DE BAT DAU       |" << endl;
    cout << "\t\t\t|________________________________________________|" << endl;
    user.input();

    
    while (true) 
    {
        system("cls");
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
            case 0:
                cout << "Thoat chuong trinh. Tam biet!" << endl;
                system("cls");
                return 0;

            case 1:
            {
                system("cls");
                while (true)
                {
                    cout <<"\n\t\t\t+---------------------------ACCOUNT WINDOW---------------------------+";
                    cout <<"\n\t\t\t|                         0. Exit Window                             |";
                    cout <<"\n\t\t\t|                         1. Them tai khoan                          |";
                    cout <<"\n\t\t\t|                         2. Xoa tai khoan                           |";
                    cout <<"\n\t\t\t|                         3. Cap nhat tai khoan                      |";
                    cout <<"\n\t\t\t|____________________________________________________________________|" << endl;

                    int Acc_Choice;
                    cout << "\nNhap lua chon thao tac: ";
                    cin >> Acc_Choice;

                    do {
                        if (Acc_Choice < 0 && Acc_Choice > 3)
                        {
                            cout << "Khong hop le. Nhap lai lua chon: ";
                            cin >> Acc_Choice;
                        }
                    } while (Acc_Choice < 0 && Acc_Choice > 3);

                    cin.ignore();
                    switch (Acc_Choice)
                    {
                        case 0:
                            break;
                        case 1:
                            cout << "=== Them tai khoan ===" << endl;
                            user.addAcount();
                            break;
                        case 2:
                            cout << "=== Xoa tai khoan ===" << endl;
                            user.deleteAccount();
                            break;
                        case 3:
                            cout << "=== Cap nhat tai khoan ===" << endl;
                            user.updateAccount();
                            break;
                    }
                    if (Acc_Choice == 0)
                        break;
                }
                break;
            }

            case 2:
            {
                system("cls");
                while (true)
                {
                    cout <<"\n\t\t\t+-------------------------TRANSACTION WINDOW-------------------------+";
                    cout <<"\n\t\t\t|                          0. Exit Window                            |";
                    cout <<"\n\t\t\t| 1. Thuc hien giao dich                   5. Cap nhat khoan cho vay |";
                    cout <<"\n\t\t\t| 2. Thuc hien vay/cho vay                 6. Cap nhat khoan vay     |";
                    cout <<"\n\t\t\t| 3. Cap nhat giao dich                    7. Xoa khoan cho vay      |";
                    cout <<"\n\t\t\t| 4. Xoa giao dich                         8. Xoa khoan vay          |";
                    cout <<"\n\t\t\t|____________________________________________________________________|" << endl;

                    int Trans_Choice;
                    cout << "\nNhap lua chon thao tac: ";
                    cin >> Trans_Choice;

                    do {
                        if (Trans_Choice < 0 && Trans_Choice > 8)
                        {
                            cout << "Khong hop le. Nhap lai lua chon: ";
                            cin >> Trans_Choice;
                        }
                    } while (Trans_Choice < 0 && Trans_Choice > 8);

                    cin.ignore();
                    switch (Trans_Choice)
                    {
                        case 0:
                            break;
                        case 1:
                            cout << "=== Thuc hien giao dich ===" << endl;
                            user.addTransaction();
                            break;
                        case 2:
                            cout << "=== Thuc hien cho vay/vay ===" << endl;
                            cout << "   1. Them khoan vay" << endl;
                            cout << "   2. Them khoan cho vay" << endl;
                            int subChoice;
                            cout << "Nhap lua chon: ";
                            cin >> subChoice;

                            do {
                                if (subChoice != 1 && subChoice != 2)
                                {
                                    cout << "Khong hop le. Nhap lai lua chon: ";
                                    cin >> subChoice;
                                }
                            } while (subChoice != 1 && subChoice != 2);
                            
                            if (subChoice == 1)
                                user.addBorrow();
                            else if (subChoice == 2)
                                user.addLoan();
                            break;
                        case 3:
                            cout << "=== Cap nhat giao dich ===" << endl;
                            user.updateTransaction();
                            break;
                        case 4:
                            cout << "=== Xoa giao dich ===" << endl;
                            user.deleteTransaction();
                            break;
                        case 5:
                            cout << "=== Cap nhat khoan cho vay ===" << endl;
                            user.updateLoan();
                            break;
                        case 6:
                            cout << "=== Cap nhat khoan vay ===" << endl;
                            user.updateBorrow();
                            break;
                        case 7:
                            cout << "=== Xoa khoan cho vay ===" << endl;
                            user.deleteLoan();
                            break;
                        case 8:
                            cout << "=== Xoa khoan vay ===" << endl;
                            user.deleteBorrow();
                            break;
                    }
                    if (Trans_Choice == 0)
                        break;
                }
                break;
            }
                
            case 3:
            {
                while (true)
                {
                    system("cls");
                    cout <<"\n\t\t\t+----------------------------REPORT WINDOW---------------------------+";
                    cout <<"\n\t\t\t|                           0. Exit Window                           |";
                    cout <<"\n\t\t\t| 1. Thong tin tai khoan                      2. Thong tin giao dich |";
                    cout <<"\n\t\t\t|____________________________________________________________________|" << endl;

                    int Rp_Choice;
                    cout << "\nNhap lua chon thao tac: ";
                    cin >> Rp_Choice;

                    do {
                        if (Rp_Choice < 0 && Rp_Choice > 2)
                        {
                            cout << "Khong hop le. Nhap lai lua chon: ";
                            cin >> Rp_Choice;
                        }
                    } while (Rp_Choice < 0 && Rp_Choice > 2);

                    cin.ignore();
                    switch (Rp_Choice)
                    {
                        case 0:
                            break;
                        case 1:
                            system("cls");
                            while (true)
                            {
                                cout <<"\n\t\t\t+------------------------------ACCOUNT-------------------------------+";
                                cout <<"\n\t\t\t|                          0. Exit Window                            |";
                                cout <<"\n\t\t\t|                   1. Xuat thong tin nguoi dung                     |";
                                cout <<"\n\t\t\t|                   2. Xuat danh sach tai khoan                      |";
                                cout <<"\n\t\t\t|                   3. Xem thong tin so du nguoi dung                |";
                                cout <<"\n\t\t\t|                   4. Xem so du cua tung tai khoan                  |";
                                cout <<"\n\t\t\t|____________________________________________________________________|" << endl;

                                int Acc_Rp_Choice;
                                cout << "\nNhap lua chon thao tac: ";
                                cin >> Acc_Rp_Choice;

                                do {
                                    if (Acc_Rp_Choice < 0 && Acc_Rp_Choice > 4)
                                    {
                                        cout << "Khong hop le. Nhap lai lua chon: ";
                                        cin >> Acc_Rp_Choice;
                                    }
                                } while (Acc_Rp_Choice < 0 && Acc_Rp_Choice > 4);

                                switch (Acc_Rp_Choice)
                                {
                                    case 0:
                                        break;
                                    case 1:
                                        cout << "=== Xuat thong tin nguoi dung ===" << endl;
                                        user.display();
                                        break;
                                    case 2:
                                        cout << "=== Xuat danh sach tai khoan ===" << endl;
                                        user.showAccount();
                                        break;
                                    case 3:
                                        cout << "=== Xem thong tin so du ===" << endl;
                                        user.displayBalanceInfo();
                                        break;
                                    case 4:
                                        cout << "=== Xem so du cua tung tai khoan ===" << endl;
                                        user.displayAllAccountBalances();
                                        break;
                                    default:
                                        break;
                                }
                                if (Acc_Rp_Choice == 0)
                                    break;
                            }
                            break;
                        case 2:
                            system("cls");
                            while (true)
                            {
                                cout <<"\n\t\t\t+------------------------------BALANCE-------------------------------+";
                                cout <<"\n\t\t\t|                          0. Exit Window                            |";
                                cout <<"\n\t\t\t|                 1. Hien thi lich su giao dich                      |";
                                cout <<"\n\t\t\t|                 2. Hien thi bao cao tai khoan                      |";
                                cout <<"\n\t\t\t|                 3. Hien thi bao cao khoan vay/cho vay              |";
                                cout <<"\n\t\t\t|____________________________________________________________________|" << endl;

                                int Bal_Rp_Choice;
                                cout << "\nNhap lua chon thao tac: ";
                                cin >> Bal_Rp_Choice;

                                do {
                                    if (Bal_Rp_Choice < 0 && Bal_Rp_Choice > 3)
                                    {
                                        cout << "Khong hop le. Nhap lai lua chon: ";
                                        cin >> Bal_Rp_Choice;
                                    }
                                } while (Bal_Rp_Choice < 0 && Bal_Rp_Choice > 3);

                                cin.ignore();
                                switch (Bal_Rp_Choice)
                                {
                                    case 0:
                                        break;
                                    case 1:
                                        cout << "=== Hien thi lich su giao dich ===" << endl;
                                        user.transactionHistory();
                                        break;
                                    case 2:
                                        cout << "=== Hien thi bao cao tai khoan ===" << endl;
                                        user.reportAccount();
                                        break;
                                    case 3:
                                        cout << "=== Hien thi bao cao khoan vay/cho vay ===" << endl;
                                        user.reportLoan_Borrow();
                                        break;
                                    
                                    default:
                                        break;
                                }
                                if (Bal_Rp_Choice == 0)
                                    break;
                            }
                            break;
                    }
                    if (Rp_Choice == 0)
                        break;
                }
                break;
            }
            default:
                cout << "Lua chon khong hop le, vui long chon lai." << endl;
        }
        cout << endl;
    }
    return 0;
}
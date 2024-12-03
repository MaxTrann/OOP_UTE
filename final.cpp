#include <iostream>
#include "User.h"

using namespace std;

// Ham hien thi menu
void showMenu() {
    cout << "==================== MENU ====================" << endl;
    cout << "1. Them nguoi dung" << endl;
    cout << "2. Them tai khoan" << endl;
    cout << "3. Thuc hien giao dich" << endl;
    cout << "4. Thuc hien vay/muon" << endl;
    cout << "5. Hien thi lich su giao dich" << endl;
    cout << "6. Hien thi bao cao tai khoan" << endl;
    cout << "7. Hien thi bao cao khoan vay/muon" << endl;
    cout << "8. Xuat thong tin nguoi dung" << endl;
    cout << "9. Xuat danh sach tai khoan" << endl;
    cout << "10. Xem thong tin so du" << endl;
    cout << "11. Xem so du cua tung tai khoan" << endl;
    cout << "12. Cap nhat giao dich" << endl;
    cout << "13. Cap nhat khoan vay" << endl;
    cout << "14. Cap nhat khoan muon" << endl;
    cout << "15. Xoa giao dich" << endl;
    cout << "16. Xoa khoan vay" << endl;
    cout << "17. Xoa khoan muon" << endl;
    cout << "18. Thoat" << endl;
    cout << "=============================================" << endl;
    cout << "\nChon mot tuy chon: ";
}

int main() {
    User user;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                cout << "=== Them nguoi dung moi ===" << endl;
                user.input();
                cout << "Nguoi dung da duoc them thanh cong!" << endl;
                break;
            case 2:
                cout << "=== Them tai khoan ===" << endl;
                user.addAcount();
                break;
            case 3:
                cout << "=== Thuc hien giao dich ===" << endl;
                user.addTransaction();
                break;
            case 4:
                cout << "=== Thuc hien vay/muon ===" << endl;
                cout << "1. Them khoan vay" << endl;
                cout << "2. Them khoan muon" << endl;
                int subChoice;
                cout << "Nhap lua chon: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    user.addLoan();
                } else if (subChoice == 2) {
                    user.addBorrow();
                } else {
                    cout << "Lua chon khong hop le!" << endl;
                }
                break;
            case 5:
                cout << "=== Hien thi lich su giao dich ===" << endl;
                user.transactionHistory();
                break;
            case 6:
                cout << "=== Hien thi bao cao tai khoan ===" << endl;
                user.reportAccount();
                break;
            case 7:
                cout << "=== Hien thi bao cao khoan vay/muon ===" << endl;
                user.reportLoan_Borrow();
                break;
            case 8:
                cout << "=== Xuat thong tin nguoi dung ===" << endl;
                user.display();
                break;
            case 9:
                cout << "=== Xuat danh sach tai khoan ===" << endl;
                user.showAccount();
                break;
            case 10:
                cout << "=== Xem thong tin so du ===" << endl;
                user.displayBalanceInfo();
                break;
            case 11:
                cout << "=== Xem so du cua tung tai khoan ===" << endl;
                user.displayAllAccountBalances();
                break;
            case 12:
                cout << "=== Cap nhat giao dich ===" << endl;
                user.updateTransaction();
                break;
            case 13:
                cout << "=== Cap nhat khoan vay ===" << endl;
                user.updateLoan();
                break;
            case 14:
                cout << "=== Cap nhat khoan muon ===" << endl;
                user.updateBorow();
                break;
            case 15:
                cout << "=== Xoa giao dich ===" << endl;
                user.deleteTransaction();
                break;
            case 16:
                cout << "=== Xoa khoan vay ===" << endl;
                user.deleteLoan();
                break;
            case 17:
                cout << "=== Xoa khoan muon ===" << endl;
                user.deleteBorrow();
                break;
            case 18:
                cout << "Thoat chuong trinh. Tam biet!" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long chon lai." << endl;
        }
        cout << endl;
    }

    return 0;
}

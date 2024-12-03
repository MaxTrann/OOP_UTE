#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

string getMaskedPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}
// cach su dung: include thu vien vao
// string password = getMaskedPassword()

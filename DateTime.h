#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class DateTime{
private:
	int hour, minute;
	int day, month, year;
public:
    DateTime()
    {
        this->hour = 0;
        this->minute = 0;
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
	void input(){
		do{
			cout << "Nhap gio: "; cin >> this->hour;
			cout << "Nhap phut: "; cin >> this->minute;
			if (this->hour < 0 || this->hour > 23 || this->minute < 0 || this->minute > 59)
				cout << "Du lieu nhap khong hop le! Vui long nhap lai!\n";
		} while(this->hour < 0 || this->hour > 23 || this->minute < 0 || this->minute > 59);

		do{
			cout << "Nhap ngay: "; cin >> this->day;
			cout << "Nhap thang: "; cin >> this->month;
			cout << "Nhap nam: "; cin >> this->year;
			if (this->month < 1 || this->month > 12 || this->day < 1 || this->day > this->daysMonth())
				cout << "Du lieu nhap khong hop le! Vui long nhap lai!\n";
		}while(this->month < 1 || this->month > 12 || this->day < 1 || this->day > this->daysMonth());
	}
	void display(){
		cout << setfill('0') << setw(2) << this->hour << ":" << setw(2) << this->minute << " " 
		<< setw(2) << this->day << "-" 
		<< setw(2) << this->month << "-" 
		<< setw(4) << this->year << endl;
	}
	int daysMonth(){
			switch(this->month){
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					return 31;
				case 4: case 6: case 9: case 11:
					return 30;
				case 2:
					if (this->year % 400 == 0 || (this->year % 100 != 0 && this->year % 4 == 0))
						return 29;
					else 
						return 28; 
				default:
					return 0;
			}
		}
	// Hàm cộng thêm số ngày hiện tại
	void addDays(int n){
		this->day += n;
		// xử lí tràn ngày 
		while (this->day > daysMonth()){
			this->day -= daysMonth();
			this->month++;

			if (this->month > 12){
				this->month = 1;
				this->year++;
			}
		}
	}
};


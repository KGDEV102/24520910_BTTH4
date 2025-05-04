#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class Ngay
{
private:
	int ngay, thang, nam;
	
public:
	~Ngay();
	Ngay();
	void Nhap();
	void Xuat() const;
	int tinhSoNgayTrongThang(int, int) const;
	int tinhSoNgayTrongNam(int) const;
	bool kiemTraHopLe() const;
	Ngay timNgayHomSau() const;
	Ngay timNgayHomTruoc() const;
	friend istream& operator>>(istream&, Ngay&);
	friend istream& operator>>(istream&, Ngay&);
	friend ostream& operator<<(ostream&, const Ngay&);
	friend Ngay operator + (const Ngay&, int);
	friend Ngay operator + (int,const Ngay& );
	friend Ngay operator - ( const Ngay&, int n);
	friend Ngay operator - (int, const Ngay&);
	Ngay operator++(int);
	Ngay operator++();
	Ngay operator--(int);
	Ngay operator--();
};


#pragma once
#include<iostream>
using namespace std;
class SoPhuc
{
private:
	float iThuc, iAo;
public:
	SoPhuc();
	friend istream& operator >>(istream&, SoPhuc&);
	friend ostream& operator <<(ostream&, SoPhuc&);
	SoPhuc& operator=(const SoPhuc&);
	SoPhuc operator+ (const SoPhuc&);
	SoPhuc operator- (const SoPhuc&);
	SoPhuc operator* (const SoPhuc&);
	SoPhuc operator/ (const SoPhuc&);
	bool operator== (const SoPhuc&);
	bool operator!= (const SoPhuc&);
	void Nhap();
	void Xuat();
};


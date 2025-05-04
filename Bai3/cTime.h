#pragma once
#include<iostream>
using namespace std;
class CTime
{
private:
	int gio, phut, giay;
	
public:
	CTime();
	CTime(int, int, int);
	CTime(const CTime&);
	~CTime();
	friend istream& operator>>(istream&,  CTime&);
	friend ostream& operator<<(ostream&, const CTime&);
	
	CTime operator+ (int);
	friend CTime operator+ (int, CTime&);
	CTime operator- (int);
	friend CTime operator- (int, CTime&);
	CTime operator++();
	CTime operator++(int);
	CTime operator--();
	CTime operator--(int);

};


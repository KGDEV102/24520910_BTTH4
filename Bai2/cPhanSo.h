#pragma once
#include<iostream>
using namespace std;
class cPhanSo
{
private:
    int tu, mau;
public:
   
    cPhanSo(int =0, int=1);
    cPhanSo(const cPhanSo&);
    friend istream& operator>>(istream&, cPhanSo&);
    friend ostream& operator<<(ostream&, cPhanSo&);
    cPhanSo& operator=(const cPhanSo&);
    cPhanSo operator + (const cPhanSo&);
    cPhanSo operator - (const cPhanSo&);
    cPhanSo operator * (const cPhanSo&);
    cPhanSo operator / (const cPhanSo&);
    bool operator==(const cPhanSo&);
    bool operator>(const cPhanSo&);
    bool operator<(const cPhanSo&);
};


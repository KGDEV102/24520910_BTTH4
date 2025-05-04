#include"cPhanSo.h"
cPhanSo::cPhanSo(int x, int y) {
	tu = x;
	mau = y;
}
cPhanSo::cPhanSo(const cPhanSo& a) {
	tu = a.tu;
	mau = a.mau;
}
istream& operator>>(istream& is, cPhanSo& a) {
	cout << "Nhap tu: ";
	is >> a.tu;
	do {
		cout << "Nhap mau: ";
		is >> a.mau;
	} while (a.mau == 0);
	return is;
}
ostream& operator<<(ostream& os, cPhanSo& a) {

	if (a.tu == 0) {
		os << "0";
	}
	else if (a.mau < -1) {
		os << -a.tu << "/" << a.mau;
	}
	else if (a.mau == -1) {
		os << -a.tu;
	}
	else if (a.mau == 1) {
		os << a.tu;
	}
	else {
		os << a.tu << "/" << a.mau;
	}
	return os;
}
cPhanSo cPhanSo::operator+(const cPhanSo& a) {
	cPhanSo res;
	res.tu = tu * a.mau + mau * a.tu;
	res.mau = mau * a.mau;
	return res;
}
cPhanSo cPhanSo::operator-(const cPhanSo& a) {
	cPhanSo res;
	res.tu = tu * a.mau - mau * a.tu;
	res.mau = mau * a.mau;
	return res;
}
cPhanSo cPhanSo::operator*(const cPhanSo& a) {
	cPhanSo res;
	res.tu = tu * a.tu;
	res.mau = mau * a.mau;
	return res;
}
cPhanSo cPhanSo::operator/(const cPhanSo& a) {
	cPhanSo res;
	res.tu = tu * a.mau;
	res.mau = mau * a.tu;
	return res;
}
cPhanSo& cPhanSo::operator=(const cPhanSo& a) {
	tu = a.tu;
	mau = a.mau;
	return *this;
}
bool cPhanSo::operator==(const cPhanSo& a) {
	if (tu == a.tu && mau == a.mau) return true;
	return false;
}
bool cPhanSo::operator>(const cPhanSo& a) {
	return tu * a.mau > a.tu * mau;
}
bool cPhanSo::operator<(const cPhanSo& a) {
	return tu * a.mau < a.tu * mau;
}

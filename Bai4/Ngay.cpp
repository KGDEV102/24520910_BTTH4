#include"Ngay.h"
Ngay::Ngay() {
	ngay = 0;
	thang = 0;
	nam = 0;
}
Ngay::~Ngay() {
	return;
}
void Ngay::Nhap() {
	do {
		cout << "Nhap ngay thang nam: ";
		cin >> ngay >> thang >> nam;
	} while (!kiemTraHopLe());
}
void Ngay::Xuat() const {
	cout << ngay << " - " << thang << " - " << nam;
}
int Ngay::tinhSoNgayTrongThang(int thang, int nam) const {
	switch (thang) {
	case 1:case 3: case 5: case 7: case 8:  case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (nam % 400 || (nam % 4 == 0 && nam % 100 != 0)) {
			return 29;
		}
		else {
			return 28;
		}
	}
}
int Ngay::tinhSoNgayTrongNam(int nam) const {
	return (nam % 400 || (nam % 4 == 0 && nam % 100 != 0)) ? 366 : 365;
}
bool Ngay::kiemTraHopLe() const {
	return thang >= 1 && thang <= 12 && ngay >= 1 && ngay <= tinhSoNgayTrongThang(thang,nam) && nam > 0;
}

Ngay Ngay::timNgayHomSau() const {
	Ngay ngayketiep;
	if (ngay == tinhSoNgayTrongThang(thang,nam)) {
		if (thang == 12) {
			ngayketiep.ngay = 1;
			ngayketiep.thang = 1;
			ngayketiep.nam = nam + 1;
		}
		else {
			ngayketiep.ngay = 1;
			ngayketiep.thang = thang + 1;
			ngayketiep.nam = nam;
		}
	}
	else {
		ngayketiep.ngay = ngay + 1;
		ngayketiep.thang = thang;
		ngayketiep.nam = nam;
	}
	return ngayketiep;
}
Ngay Ngay::timNgayHomTruoc() const {
	Ngay ngayhomtruoc;
	if (ngay == 1) {
		if (thang == 1) {
			ngayhomtruoc.ngay = 31;
			ngayhomtruoc.thang = 12;
			ngayhomtruoc.nam = nam - 1;
		}
		else {
			ngayhomtruoc.thang = thang - 1;
			ngayhomtruoc.nam = nam;
			ngayhomtruoc.ngay = tinhSoNgayTrongThang(ngayhomtruoc.thang, ngayhomtruoc.nam);

		}
	}
	else {
		ngayhomtruoc.ngay = ngay - 1;
		ngayhomtruoc.thang = thang;
		ngayhomtruoc.nam = nam;
	}
	return ngayhomtruoc;
}

istream& operator>>(istream& is, Ngay& d) {
	d.Nhap();
	return is;
}

ostream& operator<<(ostream& os, const Ngay& d) {
	d.Xuat();
	return os;
}
Ngay operator +(const Ngay& ng, int n) {
	Ngay ngaytam(ng);
	ngaytam.ngay += n;
	while (ngaytam.ngay > ngaytam.tinhSoNgayTrongThang(ngaytam.thang, ngaytam.nam)) {
		ngaytam.ngay -= ngaytam.tinhSoNgayTrongThang(ngaytam.thang, ngaytam.nam);
		ngaytam.thang++;
		if (ngaytam.thang > 12) {
			ngaytam.thang = 1;
			ngaytam.nam++;
		}
	}

	return ngaytam;
}
Ngay operator+ (int n, const Ngay& ng) {
	return ng + n;
}
Ngay operator-(const Ngay& ng, int n) {
	Ngay ngaytam(ng);
	ngaytam.ngay -= n;
	while (ngaytam.ngay < 0) {
		ngaytam.thang--;
		if (ngaytam.thang == 0) {
			ngaytam.nam -= 1;
			ngaytam.thang = 12;
		}
		ngaytam.ngay = ngaytam.tinhSoNgayTrongThang(ngaytam.thang, ngaytam.nam) - abs(ngaytam.ngay);
	}
	return ngaytam;
}
Ngay operator- (int n, const Ngay& ng) {
	return ng - n;
}

Ngay Ngay::operator++() {
	*this = timNgayHomSau();
	return *this;
}

Ngay Ngay::operator++(int) {
	Ngay ngaytam(*this);
	*this = timNgayHomSau();
	return ngaytam;
}

Ngay Ngay::operator--() {
	*this = timNgayHomTruoc();
	return *this;
}

Ngay Ngay::operator--(int) {
	Ngay ngaytam(*this);
	*this = timNgayHomTruoc();
	return ngaytam;
}

#include "CTime.h"
CTime::CTime() {
	gio = 0;
	phut = 0;
	giay = 0;
}
CTime::CTime(int gio, int phut, int giay) {
	this->gio = gio;
	this->phut = phut;
	this->giay = giay;
}
CTime::CTime(const CTime& tg) {
	gio = tg.gio;
	phut = tg.phut;
	giay = tg.giay;
}
CTime::~CTime() {
	return;
}
istream& operator>>(istream& is,  CTime& tg) {
	cout << "Gio: ";
	is >> tg.gio;
	cout << "Phut: ";
	is >> tg.phut;
	cout << "Giay: ";
	is >> tg.giay;
	return is;
}
ostream& operator<<(ostream& os, const CTime& tg) {
	if (tg.gio < 10) {
		os << "0" << tg.gio << " : ";
	}
	else {
		os << tg.gio << " : ";
	}

	if (tg.phut < 10) {
		os << "0" << tg.phut << " : ";
	}
	else {
		os << tg.phut << " : ";
	}

	if (tg.giay < 10) {
		os << "0" << tg.giay;
	}
	else {
		os << tg.giay;
	}
		
	return os;
}

CTime CTime::operator+(int n) {
	CTime res(*this);
	res.giay += n;

	// Chuyển đổi nếu số giây >= 60
	res.phut += res.giay / 60;
	res.giay = res.giay % 60;

	// Chuyển đổi nếu số phút >= 60
	res.gio += res.phut / 60;
	res.phut = res.phut % 60;

	return res;
}


CTime operator+(int n,  CTime& tg) {
	return tg + n;
}
CTime CTime::operator-(int n) {
	CTime res(*this);
	res.giay -= n;
	while (res.giay < 0) {
		res.phut--;
		if (res.phut < 0) {
			res.gio--;
			res.phut = 59;
			res.giay = 60 - abs(res.giay);
		}
		else {
			res.phut--;
			res.giay = 60 - abs(res.giay);
		}
	}

	return res;
}
CTime operator-(int n, CTime& tg) {
	return tg - n;
}
// ++ tiền tố
CTime CTime::operator++() {
	giay++;
	if (giay >= 60) {
		giay = 0;
		phut++;
		if (phut >= 60) {
			phut = 0;
			gio++;
		}
	}
	return *this;
}

// ++ hậu tố
CTime CTime::operator++(int) {
	CTime temp = *this;
	++(*this); // Gọi tiền tố để xử lý chuẩn
	return temp;
}
// -- tiền tố
CTime CTime::operator--() {
	if (giay > 0) {
		giay--;
	}
	else {
		giay = 59;
		if (phut > 0) {
			phut--;
		}
		else {
			phut = 59;
			if (gio > 0) {
				gio--;
			}
			else {
				// Đã đến 00:00:00 thì không giảm nữa
				gio = 0;
				phut = 0;
				giay = 0;
			}
		}
	}
	return *this;
}


// -- hậu tố
CTime CTime::operator--(int) {
	CTime temp = *this;
	--(*this); // Gọi tiền tố để xử lý chuẩn
	return temp;
}

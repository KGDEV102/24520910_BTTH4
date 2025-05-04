#include "SoPhuc.h"
SoPhuc::SoPhuc() {
    iThuc = 0;
    iAo = 0;
}
void SoPhuc::Nhap() {
    cout << "Phan thuc: ";
    cin >> iThuc;
    cout << "Phan ao: ";
    cin >> iAo;
}
void SoPhuc::Xuat() {
    cout << "(";
    if (iThuc == 0 && iAo == 0) {
        cout << 0;
    }
    else if (iAo == 0) {
        cout << iThuc;
    }
    else if (iThuc == 0) {
        cout << iAo << "i";
    }
    else {
        if (iAo > 0) {
            cout << iThuc << " + " << iAo << "i";

        }
        else {
            cout << iThuc << " - " << -iAo << "i";
        }
    }
    cout << ")";
}
istream& operator >>(istream& is, SoPhuc& sp) {
    cout << "Phan thuc: ";
    is >> sp.iThuc;
    cout << "Phan ao: ";
    is >> sp.iAo;
    return is;
}
ostream& operator <<(ostream& os, SoPhuc& sp) {
    sp.Xuat();
    return os;
}
SoPhuc& SoPhuc::operator=(const SoPhuc&sp) {
    this->iAo = sp.iAo;
    this->iThuc = sp.iThuc;
    return *this;
}
SoPhuc SoPhuc::operator+ (const SoPhuc&sp) {
    SoPhuc res;
    res.iThuc = this->iThuc + sp.iThuc;
    res.iAo = this->iAo + sp.iAo;
    return res;
}
SoPhuc SoPhuc::operator- (const SoPhuc& sp) {
    SoPhuc res;
    res.iThuc = this->iThuc - sp.iThuc;
    res.iAo = this->iAo - sp.iAo;
    return res;
}

SoPhuc SoPhuc::operator* (const SoPhuc& sp) {
    SoPhuc res;
    res.iThuc = this->iThuc*sp.iThuc - this->iAo*sp.iAo;
    res.iAo = this->iThuc * sp.iAo + this->iAo * sp.iThuc;
    return res;
}
SoPhuc SoPhuc::operator/ (const SoPhuc& sp) {
    SoPhuc res;
    double mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    if (mau == 0) {
        throw runtime_error("Lỗi: Không thể chia cho số phức 0.");
    }
    res.iThuc = (this->iThuc * sp.iThuc + this->iAo * sp.iAo) / mau;
    res.iAo = (this->iAo * sp.iThuc - this->iThuc * sp.iAo) / mau;
    return res;
}
bool SoPhuc::operator==(const SoPhuc& sp) {
    if (this->iThuc == sp.iThuc && this->iAo == sp.iAo) {
        return true;
    }
    return false;
}
bool SoPhuc::operator!=(const SoPhuc& sp) {
    if (this->iThuc == sp.iThuc && this->iAo == sp.iAo) {
        return false;
    }
    return true;
}

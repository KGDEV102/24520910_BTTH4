#include"cPhanSo.h"
void main() {
    cPhanSo P1, P2;
    cout << "Nhap vao phan so thu nhat: " << endl;
    cin >> P1;
    cout << "Nhap vao phan so thu hai: " << endl;
    cin >> P2;
    cPhanSo res1 = P1+P2;
    cout<<P1; cout << " + "; cout<<P2; cout << " = "; cout<<res1; cout << endl;
    cPhanSo res2 = P1 - P2;
    cout<<P1; cout << " - "; cout<<P2; cout << " = "; cout<<res2; cout << endl;
    cPhanSo res3 = P1 *P2;
    cout<<P1; cout << " * "; cout<<P2; cout << " = "; cout<<res3; cout << endl;
    cPhanSo res4 = P1/ P2;
    cout<<P1; cout << " : "; cout<<P2; cout << " = "; cout<<res4; cout << endl;

    if (P1 == P2) {
        cout << "Hai phan so bang nhau ";
    }
    else if (P1 > P2) {
        cout << P1 << " > "<<P2;
    }
    else {
        cout << P1 << " < " << P2;
    }
}

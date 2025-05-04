#include"SoPhuc.h"
#include<iostream>
int main() {
    SoPhuc P1, P2;
    cout << "Nhap vao so phuc thu 1: " << endl;
    cin >> P1;
    cout << "Nhap vao so phuc thu 2: " << endl;
    cin >> P2;
    SoPhuc res1 = P1 + P2;
    cout<<P1; cout << " + ";cout<<P2; cout << " = "; cout<<res1; cout << endl;
    SoPhuc res2 = P1 - P2;
    cout << P1; cout << " - "; cout << P2; cout << " = "; cout << res2; cout << endl;
    SoPhuc res3 = P1 * P2;
    cout << P1; cout << " * "; cout << P2; cout << " = "; cout << res3; cout << endl;
    SoPhuc res4 = P1 / P2;
    cout << P1; cout << " / "; cout << P2; cout << " = "; cout << res4; cout << endl;
    if (P1 == P2) {
        cout << P1 << " = " << P2 << endl;
    }
    else {
        cout << P1 << " != " << P2 << endl;
    }
    return 0;
}

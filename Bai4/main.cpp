#include"Ngay.h"
int main() {
	Ngay d, d1, d2;
	cin >> d;
	d1 = d + 30;
	cout << d1 << endl;
	d2 = d - 15;
	cout << d2 << endl;
	Ngay d3 = ++d;
	cout << "Sau khi dat ++ truoc: " << d3 << endl;
	Ngay d4 = d++;
	cout << "Sau khi dat ++ sau: " << d4 << endl;
	Ngay d5; cin >> d5;
	Ngay d6 = --d5, d7 = d5--;
	cout << "Sau khi dat -- truoc: " << d6 << endl;
	cout << "Sau khi dat -- sau: " << d7 << endl;


	
}

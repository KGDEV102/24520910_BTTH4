#include"CTime.h"
int main() {
	CTime  tg2(9, 30, 0);
	cout << tg2<<endl;
	CTime tg3 = tg2 + 5000;
	cout << tg3 << endl;
	CTime tg4 = 3600 + tg2;
	cout << tg4 << endl;
	CTime tg5 = tg2 - 4000;
	cout << tg5 << endl;
	CTime tg6 = 5000 - tg2;
	cout << tg6 << endl;
	
	cout << "Sau khi dat ++ truoc: " << ++tg2 << endl;
	
	cout << "Sau khi dat ++ sau: " << tg2++ << endl;

	CTime tg7(9,30,0);
	
	cout << "Sau khi dat -- truoc: " <<--tg7 << endl;
	
	cout << "Sau khi dat -- sau: " << tg7-- << endl;
	
	

	
	
}	

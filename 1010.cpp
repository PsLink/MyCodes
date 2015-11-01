#include <iostream>

using namespace std;

int le,store,budget,mon;

int main() {

	le = store = 0;

	for (mon=1; mon<=12; mon++) {
		cin >> budget;
		le += 300 - budget;
		if (le < 0) break;
		store += (le / 100) * 100;
		le %= 100;
	}

	if (le < 0) {
		cout << '-' << mon;
	}
	else {
		cout << le + store*1.2;
	}
	cout << endl;


	return 0;
}

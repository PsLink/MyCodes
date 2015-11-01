#include <iostream>

using namespace std;

int n;

int main() {

	cin >> n;

	int tmp = 0, tMax = 0;
	short a;

	cin >> tmp;
	n--;

	while (n>0) {
		n--;
		cin >> a;
		tmp += a;
		if (tmp > tMax) tMax = tmp;
		if (a > tmp) tmp = a;
	}

	if (tMax > 0) cout << tMax;
	else cout << "Game Over";
	
	return 0;
}

#include <iostream>

using namespace std;

int m,t,u,f,d,tmp,p,a;
char ch;

int main() {

	cin >> m >> t >> u >> f >> d;

	a = u + d;
	f = f + f;
	tmp = 0;
	p = 0;

	while (p < t) {
		cin >> ch;
		if (ch == 'f') tmp += f;
		else tmp += a;
		if (tmp > m ) break;
		p++;
	}

	cout << p;
	return 0;
}

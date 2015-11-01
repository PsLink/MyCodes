#include <iostream>

using namespace std;

int a,b,c,n;
unsigned long long tmp,m1,m2,m3;

int main() {

	cin >> a >> b >> c >> n;

	int month = 0;
	m1 = 1; m2=0; m3=0;
	while (month++ < n) {
		tmp = m1*a + m2*b + m3*c;
		m3 += m2;
		m2 = m1;
		m1 = tmp;
	}

	tmp = m1 + m2 + m3;
	cout << tmp;


	return 0;
}

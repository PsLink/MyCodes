#include <iostream>
#include <iomanip>

using namespace std;


long long n;
long long x[2][2],t[2][2],d[2][2];
bool flag[1000];
int l=0;

int Fibo(long long n) {
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	n = n-1;
	while (n>1) {
		flag[l++] = n % 2;
		n /= 2;
	}

	for (int i=l-1; i>=0; i--) {
		t[0][0] = x[0][0]*x[0][0] + x[0][1]*x[1][0];
		t[0][1] = x[0][0]*x[0][1] + x[0][1]*x[1][1];
		t[1][0] = x[1][0]*x[0][0] + x[1][1]*x[1][0];
		t[1][1] = x[1][0]*x[0][1] + x[1][1]*x[1][1];

		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				x[i][j] = t[i][j] % 2010;

		if (flag[i]) {
			t[0][0] = x[0][0]*d[0][0] + x[0][1]*d[1][0];
			t[0][1] = x[0][0]*d[0][1] + x[0][1]*d[1][1];
			t[1][0] = x[1][0]*d[0][0] + x[1][1]*d[1][0];
			t[1][1] = x[1][0]*d[0][1] + x[1][1]*d[1][1];

			for (int i=0; i<2; i++)
				for (int j=0; j<2; j++)
					x[i][j] = t[i][j] % 2010;
		}

	}

	return x[0][0];
}


int main() {

	x[0][0] = x[0][1] = x[1][0] = 1;
	x[1][1] = 0;

	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			d[i][j] = x[i][j];

	cin >> n;
	cout << Fibo(n) <<endl;
	return 0;
}

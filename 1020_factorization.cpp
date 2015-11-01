#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long n;
double a;
int tmp,prime[5000],ans[5000];


int main() {

	int count = 0;
	bool flag;

	for (int i=2; i<47000; i++) {
		flag = true;
		a = sqrt(i);
		tmp = (int) a;
		for (int j=2; j<=tmp; j++)
			if (i % j == 0) {
				flag = false;
				break;
			}
		if (flag) {
			prime[count] = i;
			count ++;		
		}
	}

	cin >> n;

	a = sqrt(n);

	tmp = (int) a;

	cout << n << '=';

	int ii = 0;

	while (prime[ii] <= tmp) {
		while ((n % prime[ii]) == 0) {
			ans[ii]++;
			n = n / prime[ii];
		}
		if (n == 1) break;
		ii++;
	}
	for (int i=0; i<=ii; i++)
		if (ans[i] > 0) {
			cout << prime[i] << '(' << ans[i] << ')';
		}
	if (n > 1) cout << n << "(1)";
	cout << endl;


	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int n,len,test;
string s;


int main() {

	cin >> n;
	while (n-->0) {
		cin >> s;
		len = s.length();
		test = 0;
		for (int i=0; i<len; i++) {
			if (s[i] == '(') {
				test ++;
			}
			else if (s[i] == ')') {
				test --;
				if (test < 0) break;

			} else {
				test = -1;
				break;
			}
		}
		if (test != 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}


	return 0;
}

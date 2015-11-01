#include <iostream>

using namespace std;

int n;

bool check[12];
short data[12][12];
short sum[12][12];


int main() {

	cin >> n;
	bool flag;

	while (n>0) {
		n--;
		flag = true;
		for (int i=1; i<=9; i++) {
			for (int j=1; j<=9; j++)
				cin >> data[i][j];
		}
/*
		for (i=1; i<=10; i++) {
			for (j=1; j<=10; j++) 
				sum[i][j] = data[i][j] + sum[i]

		}
*/
		for (int i=1; i<=9; i++)
			if (flag) {
				for(int j=1; j<=9; j++) 
					check[j] = false;
				for(int j=1; j<=9; j++)
					if (!check[data[i][j]]) {
						check[data[i][j]] = true;
					}
					else {
						flag = false;
						break;
					}
		}

		for (int i=1; i<=9; i++)
			if (flag) {
				for(int j=1; j<=9; j++) 
					check[j] = false;
				for(int j=1; j<=9; j++)
					if (!check[data[j][i]]) {
						check[data[j][i]] = true;
					}
					else {
						flag = false;
						break;
					}
		}

		for (int t=1; t<=9; t+=3) {
			for (int k=1; k<=9; k+=3) {

				for(int j=1; j<=9; j++) 
					check[j] = false;

				for (int i=0; i<3; i++)
					if (flag) {
						for (int j=0; j<3; j++) {
							if (!check[data[i+t][j+k]]) {
								check[data[i+t][j+k]] = true;
							}
							else {
								flag = false;
								break;
							}

						}
					}
			}
		}

		if (flag) {
			cout << "Right" << endl;
		}
		else {
			cout << "Wrong" << endl;
		}

	}
	return 0;
}

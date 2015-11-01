#include <iostream>

using namespace std;

int map[105][105],L,len;
short x[100000],y[100000];
short dx[4] = {0,0,1,-1}, dy[4]={1,-1,0,0};

int main() {

	int tmp;
	len = 0;
	cin >> L;
	for (int i=1; i<=L; i++) {
		for (int j=1; j<=L; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 1) {
				x[len] = i;
				y[len] = j;
				len++;
			} 
			if (tmp == 2) map[i][j] = -1;
		}
	}

	for (int i = 0; i<=L+1; i++) map[i][0] = map[i][L+1] = map[0][i] = map[L+1][i] = -1;

/*
	for (int i=0; i<=len+1; i++) {
		for (int j=0; j<=len+1; j++) 
			cout << map[i][j] << ' ';
		cout << endl;
	}
*/

	//----------------

	int p = 0,step = 0,tx,ty;
	while (p<len) {
		tx = x[p];
		ty = y[p];

		for (int k=0; k<4; k++)
			if (map[tx+dx[k]][ty+dy[k]] == 0) {
				map[tx+dx[k]][ty+dy[k]] = map[tx][ty] + 1;
				x[len] = tx+dx[k];
				y[len] = ty+dy[k];
				len++;
			}

		p++;
		if (map[x[p]][y[p]] > map[tx][ty]) 
			step++;
	}

	cout << step << endl;


	return 0;
}

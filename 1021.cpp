#include <iostream>
#include <iomanip>

using namespace std;

int n,endN,di,x,y;
int map[155][155];
int dx[5] = {0,1,0,-1}, dy[5] = {1,0,-1,0};

int main() {

	cin >> n;

	endN = n*n;

	di = 0;
	x = 1;
	y = 1;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			map[i][j] = -1;

	for (int i=1; i<=endN; i++) {
		map[x][y] = i;
		if (map[x+dx[di]][y+dy[di]] > -1) {
			di++;
			di %= 4;
		}
		x += dx[di];
		y += dy[di];
	}

	for (int i = 1; i<=n; i++) {
		for (int j=1; j<=n; j++) 
			cout << setw(6) << map[i][j];
		cout << endl;
	}


	return 0;
}

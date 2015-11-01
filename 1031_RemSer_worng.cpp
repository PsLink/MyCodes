#include <iostream>


using namespace std;

int n;
short map[105][105],dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
struct rcrd
{
	short val,l;
	short cord[105];
} state[105][105];

int max(int a,int b) {return(a > b ? a : b);}
int min(int a,int b) {return(a < b ? a : b);}

bool fitin(int tx,int ty,short tmin) {
	for (int i=0; i<state[tx][ty].l; i++) 
		if (state[tx][ty].cord[i] == tmin) return false;
	return true;
}

void rd_srh(int x, int y, short tmin, short tmax) {
	if (x == y && x == n) {
		return;
	}

	short ta,ti,tv,tx,ty;

	for (int i = 3; i>=0; i--)
		if (map[x+dx[i]][y+dy[i]]>-1) {
			tx = x+dx[i];
			ty = y+dy[i];
			tv = map[tx][ty];
			ta = max(tmax,tv);
			ti = min(tmin,tv);
			tv = ta - ti;
			if (tv < state[tx][ty].val) {
				state[tx][ty].val = tv;
				state[tx][ty].l = 1;
				state[tx][ty].cord[0] = tmin;
				rd_srh(x+dx[i],y+dy[i],ti,ta);
			}

			if ((tv == state[tx][ty].val) && (fitin(tx,ty,tmin))) {
				state[tx][ty].cord[state[tx][ty].l] = tmin;
				state[tx][ty].l++;
				rd_srh(tx,ty,ti,ta);
			}

	}
}

int main() {
	cin >> n;

	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) {
		cin >> map[i][j];
		state[i][j].val = 200;
	}

	for (int i=0; i<=n+1; i++) {
		map[i][0] = map[i][n+1] = map[0][i] = map[n+1][i] = -1;
	}

	rd_srh(1,1,map[1][1],map[1][1]);

	cout << state[n][n].val << endl;

	return 0;
}

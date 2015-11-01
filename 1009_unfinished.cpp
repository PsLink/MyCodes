#include <iostream>
#include <iomanip>

using namespace std;

struct tradeType {
	int t;
	short a,d;
	bool flag;

} rec[55];

int n,m,ot,ov,t,v;
double res,tCost;


int main() {

	cin >> m;

	for (int i=0; i<m; i++) {
		cin >> rec[i].t >> rec[i].a >> rec[i].d;
		rec[i].a *= 100;
		rec[i].flag = true;
	}

	res = 0;

	cin >> n;
	n--;
	cin >> ot >> ov; 
	while (n>0) {
		n--;
		cin >> t >> v;

		for (int p=0; p<m; p++)
			if (rec[p].t < t && rec[p].t >= ot) {
				tCost = ov*rec[p].a*0.002;
				if (tCost < 5) tCost = 5;
				tCost += rec[p].a/1000+1;

				if (rec[p].d == 2) {
					tCost += ov*rec[p].a*0.001;
					res += (ov*rec[p].a - tCost);
				}
				else {
					res -= (ov*rec[p].a + tCost);
				}
				rec[p].flag = false;
			}
		ot = t;
		ov = v;
	}

	for (int p=0; p<m; p++)
			if (rec[p].flag) {
				tCost = ov*rec[p].a*0.002;
				if (tCost < 5) tCost = 5;
				tCost += rec[p].a/1000+1;

				if (rec[p].d == 2) {
					tCost += ov*rec[p].a*0.001;
					res += (ov*rec[p].a - tCost);
				}
				else {
					res -= (ov*rec[p].a + tCost);
				}
			}

    int tmp = (int) (res*1000);
    if (tmp % 10 > 4) res +=0.01;
	cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;

	
	return 0;
}

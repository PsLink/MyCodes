#include <stdio.h>
#include <algorithm>

using namespace std;

int n,p,l;
long long maxl;
struct cord{
	long long x,y;
 } data[20005];

long long ans;

bool cmp(cord a, cord b) {
	return (a.x < b.x);
}


int main() {

	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%lld %lld",&data[i].x,&data[i].y);
	}

	sort(data,data+n,cmp);

	ans = 0; p = 0;
	while (p<n) {
		l = p;
		maxl = data[p].y;
		while ((data[l].x < maxl) && (l<n)) {
			maxl = maxl > data[l].y ? maxl : data[l].y;
			l++;
		}
		ans = ans + maxl - data[p].x;
		p = l;
	}

	printf("%lld\n",ans);
	return 0;
}

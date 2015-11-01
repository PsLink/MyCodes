#include <stdio.h>
#include <algorithm>

using namespace std;

struct plane
{
	int t,u,g,index;
	
} heap[1005];

int n,maxT,s,last;
int ans[1005];

bool flag;

bool cmp(plane a, plane b) {
	return (a.t < b.t);
}

void heap_swap(int a, int b) {
	plane tmp;
	tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}

void heap_down(int i) {
	if (i*2+1 > n) return;
	if ((i*2 == n) && (heap[i].t > heap[i*2].t)) {
		heap_swap(i,i*2);
		return;
	}

	if (heap[i*2].t < heap[i*2+1].t) {
		if (heap[i].t > heap[i*2].t) {
			heap_swap(i,i*2);
			heap_down(i*2);
		}
	} else {
		if (heap[i].t > heap[i*2+1].t) {
			heap_swap(i,i*2+1);
			heap_down(i*2+1);
		}
	}

}


int main() {

	scanf("%d %d %d",&n,&maxT,&s);
	ans[n+1] = -1;

	//scanf("%d %d %d",&heap[1].t ,&heap[1].u, &heap[1].g);

	for (int i=1; i<=n; i++) {
		scanf("%d %d %d",&heap[i].t ,&heap[i].u, &heap[i].g);
		heap[i].index = i;
	}

	sort(heap+1,heap+1+n,cmp);

	int t,u,g;

	last = 0;
	flag = false;

	while (n > 0) {
		t = heap[1].t; u = heap[1].u; g = heap[1].g;
		if (t > maxT) break;
		if (t == heap[2].t || t == heap[3].t) {
			printf("CHANGE BOYFRIEND\n");
			flag = true;
			break;
		}
		if ((t+u) >= last) { // take off
			last = t+u+s;
			if (last - s > maxT) break;
			ans[heap[1].index] = t+u;
			heap_swap(1,n);
			n--; 
			heap_down(1);
		} else {
			heap[1].t = t + g;
			heap_down(1);
		}
	}


	if (!flag) {
		if (n > 0) {
			printf("GO DATING\n");
		} else {
		
			for (int i=1; ans[i] >= 0; i++) {
				printf("%d\n", ans[i]);
			}
		}
	}
	return 0;
}

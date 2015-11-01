#include <iostream>
#include <string>

using namespace std;

int n,p,x,y;
string data[105];

struct node
{
	short val,next;
	
} list[105];

void insert(int y, int x) {

	while (list[x].next > 0) {
		list[x].val += list[y].val;
		x = list[x].next;
	}
	list[x].val += list[y].val;
	list[x].next = y;
}

int main() {
	cin >> n;
	getline(cin,data[0]);
	for (int i=1; i<=n; i++) {
		getline(cin,data[i]);
	}

	for (int i=1; i<=n; i++) {
		list[i].val = 1;
		list[i].next = -1;
	}


	for (int i=1; i<n; i++) {
		cin >> x >> y;
		insert(x,y);
	}


	for (int i=0; i<n; i++)
		if (list[i].val == n) {
			p = i;
		}


	while (list[p].next > 0) {
		cout << data[p] << ' ';
		p = list[p].next;
	}
	cout << data[p] << endl;


	return 0;
}

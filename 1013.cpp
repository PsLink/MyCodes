#include <iostream>

using namespace std;

int v,n,vol,val;
int f[10005];

int main()
{
	cin >> v >> n;
	for (int i=0; i<=v; i++) f[0] = 0;
	while(n>0) {
		n--;
		cin >> vol >> val;
		for (int i=vol; i<=v; i++)
			if (f[i] < (f[i-vol]+val)) f[i] = f[i-vol] + val;
	}

	cout << f[v] << endl;
    return 0;
}
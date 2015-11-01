#include <stdio.h>


int n,a,b;
int data[605][605];
int main() {

	scanf("%d",&a);
	while (a-- > 0) {
		scanf("%d %d",&n,&b);
		if (b==0) {
			for (int i=0; i<n; i++)
				for (int j=n-1; j>=0; j--)
					scanf("%d",&data[i][j]);
		}
		if (b==1) {
			for (int i=n-1; i>=0; i--)
				for (int j=0; j<n; j++)
					scanf("%d",&data[i][j]);
		}
		if (b==2) {
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					scanf("%d",&data[j][i]);
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++)
				printf("%d ",data[i][j]);
			printf("\n");
		}

	}

	return 0;
}

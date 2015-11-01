#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int data[10005];

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
}}

int main() {

	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&data[i]);
	}
	sort(data,data+n);

	for (int i=0; i<n; i++)
		printf("%d ", data[i]);

	

	
	return 0;
}

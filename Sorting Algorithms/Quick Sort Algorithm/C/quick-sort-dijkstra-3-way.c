/* ===== ===== =====

Theory of Programming

Quick sort algorithm with Dijksrta's 3-way paritioning
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>

void quickSortDijkstra(int arr[], int low, int high)
{
	if (low >= high) {
		return;
	}
	
	int i, j, swap;
	int lt = low, ht = high;
	int pivot = arr[low];
	
	for (i = low + 1; i <= high; ++i) {
		if (lt == ht) {
			break;
		}
		
		if (arr[i] < pivot) {
			swap = arr[lt];
			arr[lt] = arr[i];
			arr[i] = swap;
			
			++lt;
		} else if (arr[i] > pivot) {
			swap = arr[ht];
			arr[ht] = arr[i];
			arr[i] = swap;
			
			--ht;
			--i;
		}
	}
	
	quickSortDijkstra(arr, low, lt);
	quickSortDijkstra(arr, ht + 1, high);
}

int main()
{
	int n, i;
	
	printf("Enter the size -\n");
	scanf("%d", &n);
	
	int arr[n];
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	quickSortDijkstra(arr, 0, n - 1);
	
	printf("\n\nThe Final Sorted Array -\n");
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}

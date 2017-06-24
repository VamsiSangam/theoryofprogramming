/* ===== ===== =====

Theory of Programming

Quick sort algorithm with dual pivot
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>

void quickSortDualPivot(int arr[], int low, int high)
{
	if (low >= high) {
		return;
	}
	
	int lt = low + 1, ht = high - 1, i, temp;
	
	// Swapping 'low' and 'high' elements if neccessary
	if (arr[low] > arr[high]) {
		temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
	}
	
	// If only two elements are there, by this
	// point they are already sorted
	if (low + 1 == high) {
		return;
	}
	
	for (i = low + 1; i <= high; ++i) {
		if (i > ht) {
			// Whatever value a[i] holds beyond
			// will have a value > a[high]
			break;
		}
		
		if (arr[i] < arr[low]) {
			// a[i] < pivot1 so, falls in
			// first sub-array
			temp = arr[lt];
			arr[lt] = arr[i];
			arr[i] = temp;
			++lt;
		} else if (arr[i] > arr[high]) {
			// a[i] > pivot2 so, falls in
			// third sub-array
			temp = arr[ht];
			arr[ht] = arr[i];
			arr[i] = temp;
			--ht;
			--i;
		}
		
		// The value of a[i] that does not go to either
		// of the cases falls in second sub-array
	}
	
	// Swapping the two-pivots to correct places
	++ht;
	temp = arr[ht];
	arr[ht] = arr[high];
	arr[high] = temp;
	--lt;
	temp = arr[lt];
	arr[lt] = arr[low];
	arr[low] = temp;
	
	// Recursively applying the algorithm to sub-arrays
	quickSortDualPivot(arr, low, lt - 1);
	quickSortDualPivot(arr, lt + 1, ht - 1);
	quickSortDualPivot(arr, ht + 1, high);
}

int main()
{
	int n, i;
	
	printf("Enter the size -\n");
	scanf("%d", &n);
	
	printf("Enter %d elements -\n", n);
	
	int arr[n];
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	quickSortDualPivot(arr, 0, n - 1);
	
	printf("The Sorted Array -\n");
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

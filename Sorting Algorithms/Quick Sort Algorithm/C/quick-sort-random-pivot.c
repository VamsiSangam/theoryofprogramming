/* ===== ===== =====

Theory of Programming

Quick sort algorithm with random pivot selection
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <stdlib.h>

void quickSortRandomPivot(int arr[], int low, int high)
{
	if (low >= high) {
		// A single element is 
		// considered to be sorted
		return;
	}
	
	int mid = (rand() % (high - low)) + low;
	
	// Put the pivot at the last
	int temp = arr[mid];
	arr[mid] = arr[high];
	arr[high] = temp;
	
	int pivot = arr[high];
	int i = low;
	int j = high - 1;
	
	// The partition
	while (j >= i) {
		if (arr[j] < pivot && arr[i] > pivot) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			
			++i;
			--j;
		} else if (arr[j] < pivot && arr[i] <= pivot) {
			++i;
		} else if (arr[j] >= pivot && arr[i] > pivot) {
			--j;
		} else if (arr[j] >= pivot && arr[i] <= pivot) {
			++i;
			--j;
		}
	}
	
	// Bring the pivot back to its
	// appropriate place
	temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;
	
	quickSortRandomPivot(arr, low, i - 1);
	quickSortRandomPivot(arr, i + 1, high);
}

int main()
{
	int size, i;
	
	printf("Enter the size of the array -\n");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("Enter %d Integers -\n", size);

	for (i = 0; i < size; ++i) {
		scanf("%d", &arr[i]);
	}
	
	quickSortRandomPivot(arr, 0, size - 1);
	
	printf("\nThe Sorted Array -\n");
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}

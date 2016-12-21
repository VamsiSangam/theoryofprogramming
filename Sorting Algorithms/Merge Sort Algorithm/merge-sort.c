/* ===== ===== =====

Theory of Programming

Merge Sort Algorithm
http://theoryofprogramming.com/2015/01/29/merge-sort-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>

// Merges two sorted partitions into a bigger sorted array
void mergePartitions(int Array[], int low, int high, int LeftPartition[], int RightPartition[])
{
	int i, j, k;
	int mid = (low + high + 1) / 2;
	
	// Initialise carefully
	i = j = 0;
	k = low;
	
	while (i < mid - low && j <= high - mid) {
		if (LeftPartition[i] < RightPartition[j]) {
			Array[k] = LeftPartition[i];
			++i;
		} else {
			Array[k] = RightPartition[j];
			++j;
		}
		
		++k;
	}
	
	// Copying any leftover elements
	if (i == mid - low && j <= high - mid) {
		while (j <= high - mid) {
			Array[k] = RightPartition[j];
			++j;
			++k;
		}
	} else {
		while (i < mid - low) {
			Array[k] = LeftPartition[i];
			++i;
			++k;
		}
	}
}

// Partitions the array into two
// Does nothing if array has only one element
void mergeSort(int Array[], int low, int high)
{
	if (low < high) {
		int mid = (low + high + 1) / 2;
		int LeftPartition[mid - low];
		int RightPartition[high - mid + 1];
		int i;
		
		// Copying elements
		for (i = low; i < mid; ++i) {
			LeftPartition[i - low] = Array[i];
		}
		
		// Copying elements
		for (i = mid; i <= high; ++i) {
			RightPartition[i - mid] = Array[i];
		}
		
		// Recursive call
		mergeSort(LeftPartition, 0, mid - low - 1);
		mergeSort(RightPartition, 0, high - mid);
		// Merge the two partitions
		mergePartitions(Array, low, high, LeftPartition, RightPartition);
	}
}

int main()
{
	int n, i;
	
	printf("Enter the size of input -\n");
	scanf("%d", &n);
	
	int arr[n];
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	mergeSort(arr, 0, n - 1);
	
	printf("\nThe Sorted Array -\n");
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}

/* ===== ===== =====

Theory of Programming

Binary Search Algorithm
http://theoryofprogramming.com/2016/11/04/binary-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>

int binarySearch(int arr[], int n, int val)
{
	int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return arr[low] == val ? low : -1;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = 9;
	int i;
	
	for (i = 0; i <= 10; ++i) {
		int index = binarySearch(arr, n, i);
		
		if (index != -1) {
			printf("%d found at index %d\n", i, index);
		} else {
			printf("%d not found\n", i);
		}
	}

    return 0;
}

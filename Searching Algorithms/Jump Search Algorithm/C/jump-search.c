/* ===== ===== =====

Theory of Programming

Jump Search Algorithm
http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <math.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int jumpSearch(int arr[], int n, int val) {
    int jump = (int) sqrt(n);
    int left = 0;
    int right = 0;
	
    while (left < n && arr[left] <= val) {
        right = min(n - 1, left + jump);

        if (arr[left] <= val && arr[right] >= val) {
            break;
        }

        left += jump;
    }

    if (left >= n || arr[left] > val) {
        return -1;
    }

    right = min(n - 1, right);
	
	int i;
	
    for (i = left; i <= right && arr[i] <= val; ++i) {
        if (arr[i] == val) {
            return i;
        }
    }

    return -1;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
	int n = 8;

    printf("%d\n", jumpSearch(arr, n, 0)); // -1
    printf("%d\n", jumpSearch(arr, n, 3)); // 1
    printf("%d\n", jumpSearch(arr, n, 11)); // 5
    printf("%d\n", jumpSearch(arr, n, 16)); // -1

    return 0;
}

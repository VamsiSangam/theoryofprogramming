/* ===== ===== =====

Theory of Programming

Optimised Jump Search Algorithm
http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Pair {
	int left, right;
};

int min(int a, int b) {
	return a < b ? a : b;
}

struct Pair jumpSearchUtil(int arr[], int n, int val, int low, int high) {
    int left = low;
    int step = (int) sqrt(high - low);
    int right = 0;
	struct Pair p;
	
    while (left < high && arr[left] <= val) {
        right = min(left + step, high);

        if (arr[left] <= val && arr[right] >= val) {
            p.left = left;
            p.right = right;
            
			return p;
        }

        left = right;
    }
    
	p.left = -1;

    return p;
}

int jumpSearch(int arr[], int n, int val) {
    int low = 0, high = n - 1;

    while (high - low > 1) {
        struct Pair p = jumpSearchUtil(arr, n, val, low, high);

        if (p.left == -1) {
            return -1;
        }

        low = p.left;
        high = p.right;
    }

    return arr[low] == val ? low : arr[high] == val ? high : -1;
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

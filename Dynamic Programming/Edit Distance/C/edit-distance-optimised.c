/* ===== ===== =====

Theory of Programming

Edit Distance Algorithm - Memory Optimised
http://theoryofprogramming.com/2016/11/06/dynamic-programming-edit-distance/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10001

int min(int a, int b, int c)
{
	if (a <= b && a <= c) {
		return a;
	} else if (b <= a && b <= c) {
		return b;
	} else {
		return c;
	}
}

int editDistance(char a[], char b[])
{
	int aLength = strlen(a), bLength = strlen(b);
	int i, j;
	
	if (aLength < bLength) {
		char * tempPointer = a;
		a = b;
		b = tempPointer;
		
		int temp = aLength;
		aLength = bLength;
		bLength = temp;
	}
	
	int prev[bLength + 1];
	
	for (j = 0; j <= bLength; ++j) {
		prev[j] = j;
	}
	
	int curr[bLength + 1];
	
	for (i = 1; i <= aLength; ++i) {
		curr[0] = i;
		
		for (j = 1; j <= bLength; ++j) {
			if (a[i - 1] == b[j - 1]) {
				curr[j] = prev[j - 1];
			} else {
				curr[j] = 1 + min(
								prev[j - 1],
								prev[j], 
								curr[j - 1]);
			}
		}
		
		for (j = 0; j <= bLength; ++j) {
			prev[j] = curr[j];
			curr[j] = 0;
		}
	}
	
	return prev[bLength];
}

int main()
{
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		char a[MAX_SIZE];
		char b[MAX_SIZE];
		
		scanf("%s", a);
		scanf("%s", b);
		
		printf("%d\n", editDistance(a, b));
	}
	
    return 0;
}

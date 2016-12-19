/* ===== ===== =====

Theory of Programming

Edit Distance Algorithm
http://theoryofprogramming.com/2016/11/06/dynamic-programming-edit-distance/
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
	int dp[aLength + 1][bLength + 1];
	int i, j;
	
	for (i = 0; i <= aLength; ++i) {
		dp[i][0] = i;
	}
	
	for (j = 0; j <= bLength; ++j) {
		dp[0][j] = j;
	}
	
	for (i = 1; i <= aLength; ++i) {
		for (j = 1; j <= bLength; ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = 1 + min(
								dp[i][j - 1],
								dp[i - 1][j], 
								dp[i - 1][j - 1]);
			}
		}
	}
	
	return dp[aLength][bLength];
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

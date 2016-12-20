/* ===== ===== =====

Theory of Programming

Generating Binary Indexed Tree (BIT) or Fenwick Tree
http://theoryofprogramming.com/2014/12/24/binary-indexed-tree-or-fenwick-tree/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>

int main()
{
	int n, i, j;
	
	printf("Enter size of Frequency Table = ");
	scanf("%d", &n);
	
	int freq[n + 1];
	
	printf("Enter numbers to Frequency Table -\n");
	
	for (i = 1; i <= n; ++i) {
		scanf("%d", &freq[i]);
	}
	
	printf("\n");
	
	int bit[n + 1];

	for (i = 1; i <= n; ++i) {
		bit[i] = 0;
	}
	
	printf("Initial Fenwick Tree -\n");
	for (i = 1; i <= n; ++i) {
		printf("%d      ", bit[i]);
	}
	
	printf("\n\nThe Fenwick Tree stages per iterate -\n");
	
	for (i = 1; i <= n; ++i) {
		j = i;
		printf("freq[%d] = %d\n", i, freq[i]);
		while (j <= n) {
			bit[j] += freq[i];
			j = j + (j & (-j));
		}
		
		for (j = 1; j <= n; ++j) {
			printf("%d      ", bit[j]);
		}
		printf("\n\n");
	}
	
	printf("\nThe Final Fenwick Tree is - \n");
	for (i = 1; i <= n; ++i) {
		printf("%d ", bit[i]);
	}
	
	return 0;
}

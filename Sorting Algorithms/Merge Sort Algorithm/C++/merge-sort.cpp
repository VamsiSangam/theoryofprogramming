/* ===== ===== =====

Theory of Programming

Merge Sort Algorithm
http://theoryofprogramming.com/2015/01/29/merge-sort-algorithm/
GitHub - https://github.com/salman-bhai/theoryofprogramming
Code Contributor - Salman Shah

===== ===== ===== */

#include <bits/stdc++.h>
using namespace std;

//Variable declaration
vector<int> v;
vector<int> b;

void merge(int first, int mid, int last) {
	int i, j, k;

	for(i = first, j = first, k = mid + 1; j <= mid && k <= last; i ++) {
		if(v[j] <= v[k]) {
			b.push_back(v[j++]);
		}
		else {
			b.push_back(v[k++]);
		}
	}

	while(j <= mid) {
		b.push_back(v[j++]);
	}

	while(k <= mid) {
		b.push_back(v[k++]);
	}

	for(i = first; i <= last; i ++) {
		v[i] = b[i];
	}
}

void mergeSort(int first, int last) {
	int mid;

	if(first < last) {
		mid = (first + last)/2;
		mergeSort(first, mid);
		mergeSort(mid+1, last);
		merge(first, mid, last);
	}

	else
		return;
}

int main() {
	//Enter number of elements in the array
	int n, temp;
	scanf("%d",&n);

	//Inputting vales into the vector
	for(int i = 0; i < n; i ++) {
		scanf("%d",&temp);
		v.push_back(temp);
	}

	//Using merge sort for the vector
	mergeSort(0, n-1);

	for(int i = 0; i < n; i ++)
		printf("%d ",v[i]);
	printf("\n");

	return 0;
}
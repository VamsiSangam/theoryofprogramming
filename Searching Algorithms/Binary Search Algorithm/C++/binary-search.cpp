/* ===== ===== =====

Theory of Programming

Binary Search Algorithm
http://theoryofprogramming.com/2016/11/04/binary-search-algorithm/
GitHub - https://github.com/salman-bhai/theoryofprogramming
Code Contributor - <salman-bhai>

===== ===== ===== */
// Includes all header files required for C++ functions
#include <bits/stdc++.h>
using namespace std;


// Main Binary Search logic
int binary(int key) {
	int first = 0;
	int last = v.size() - 1;

	while(first <= last) {
		int mid = ((first + last) / 2);
		// If the middle element is the key, return the middle element
		if(v[mid] == key) {
			return mid;
		}
		// If the key is lesser than the middle element, then then it is in the left most region
		else if(v[mid] > key) {
			last = mid - 1;
		}
		// If the key is greater than the middle element, then it is in the right most region
		else {
			first = mid + 1;
		}
	}

	// If key isn't found, return -1
	return -1;
}

int main() {
	//Variable declaration
	vector<int> v;

	//Enter number of elements in the vector
	int n, temp;
	cin >> n;

	// Enter the elements in the vector
	for(int i = 0; i < n ; i ++) {
		cin >> temp;
		v.push_back(temp);
	}

	// Enter the element to be searched
	int key;
	cin >> key;

	int x = binary(v, key);

	// In case -1 is found, means key isn't present
	if(x == -1) {
		printf("Key not found!\n");
	}
	// If -1 isn't returned, key is found!
	else {
		printf("Key found at position %d\n",x + 1);
	}
	return 0;
} 

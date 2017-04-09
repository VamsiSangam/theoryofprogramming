/* ===== ===== =====

Theory of Programming

Binary Search Algorithm
http://theoryofprogramming.com/2016/11/04/binary-search-algorithm/
GitHub - https://github.com/salman-bhai/theoryofprogramming
Code Contributor - <salman-bhai>

===== ===== ===== */
//Includes all header files required for C++ functions
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

//Main Binary Search logic
int binary(int key) {
	int first = 0;
	int last = v.size()-1;

	while(first <= last) {
		int mid = ((first+last)/2);
		if(v[mid] == key) {
			return mid;
		}
		else if(v[mid] > key) {
			last = mid - 1;
		}
		else
			first = mid + 1;
	}

	return -1;
}

int main() {
	//Enter number of elements in the vector
	int n, temp;
	cin >> n;

	//Enter the elements in the vector
	for(int i = 0; i < n ; i ++) {
		cin >> temp;
		v.push_back(temp);
	}

	//Enter the element to be searched
	int key;
	cin >> key;

	int x = binary(key);

	//In case -1 is found, means key isn't present
	if(x == -1)
		printf("Key not found!\n");
	//If -1 isn't returned, key is found!
	else
		printf("Key found at position %d\n",x+1);

	return 0;
} 

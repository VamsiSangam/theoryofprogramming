/* ===== ===== =====

Theory of Programming

Binary Search Algorithm
http://theoryofprogramming.com/2016/11/04/binary-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributors - <salman-bhai>
                  - Praveen Mylavarapu (github.com/praveenmylavarapu, saipraveen.ml)

===== ===== ===== */

#include <iostream>
#include <vector>
using namespace std;

// Main Binary Search logic
int binarySearch(vector<int> v, int val) {
	int first = 0;
	int last = v.size() - 1;

	while(first <= last) {
		int mid = ((first + last) / 2);
		// If the middle element is the value, return the middle element
		if(v[mid] == val) {
			return mid;
		}
		// If the value is lesser than the middle element, then then it is in the left most region
		else if(v[mid] > val) {
			last = mid - 1;
		}
		// If the value is greater than the middle element, then it is in the right most region
		else {
			first = mid + 1;
		}
	}

	// If value isn't found, return -1
	return -1;
}

int main() {
    // Variable declaration
    vector<int> v;

	// Enter number of elements in the vector
	int n, temp;
	cout << "Enter the number of elements: ";
	cin >> n;

	// Enter the elements in the vector
	cout << "Enter " << n << " elements: ";
	
	for(int i = 0; i < n ; i ++) {
		cin >> temp;
		v.push_back(temp);
	}

	// Enter the element to be searched
	int val;
	cout << "Enter the element to be searched: ";
	cin >> val;

	int x = binarySearch(v, val);

	// In case -1 is found, means value isn't present
	if(x == -1) {
		cout << val << " not found!" << endl;
	}
	// If -1 isn't returned, value is found!
	else {
		cout << val << " found at position " << x + 1 << endl;
	}

	return 0;
}

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

	if(x == -1)
		printf("Key not found!\n");
	else
		printf("Key found at Position %d\n",x+1);

	return 0;
} 
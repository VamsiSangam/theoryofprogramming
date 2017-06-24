/* ===== ===== =====

Theory of Programming

Segment Tree Data Structure
http://theoryofprogramming.com/2015/01/27/segment-trees/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value, low, high;
	struct node * leftChild;
	struct node * rightChild;
};

// The recursive procedure which actually constructs the Segment Tre
int buildSegmentTree(int arr[], int low, int high, struct node * SegmentTree)
{
	if (low == high) {
		// we have only 1 element of the array
		SegmentTree->value = arr[low];
		SegmentTree->low = SegmentTree->high = low;
		
		return SegmentTree->value;
	}
	
	// Partition
	int mid = (low + high) / 2;
	
	SegmentTree->low = low;			// Setting bounds to the partial sum
	SegmentTree->high = high;		// that this node is associated with
	
	// Creating children
	SegmentTree->leftChild = (struct node *) calloc(1, sizeof(struct node));
	SegmentTree->rightChild = (struct node *) calloc(1, sizeof(struct node));
	SegmentTree->value = buildSegmentTree(arr, low, mid, SegmentTree->leftChild)
						+ buildSegmentTree(arr, mid + 1, high, SegmentTree->rightChild);
	
	// Must return the value to carry on recursion
	return SegmentTree->value;
}

// Allocates memory for the root and calls method
// to construct the Segment Tree
struct node * getSegmentTree(int arr[], int n)
{
	if (n <= 0) {
		return NULL;
	}
	
	struct node * SegmentTree = (struct node *) calloc(1, sizeof(struct node));
	
	buildSegmentTree(arr, 1, n, SegmentTree);
	
	return SegmentTree;
}

// A utility function used for Inorder Walk
void print(struct node * SegmentTree)
{
	printf("%d -> [%d, %d]\n", SegmentTree->value, SegmentTree->low, SegmentTree->high);
}

// In-Order Walk of Segment Tree
void inOrderWalk(struct node * SegmentTree)
{
	if (SegmentTree == NULL) {
		return;
	}
	
	inOrderWalk(SegmentTree->leftChild);
	print(SegmentTree);
	inOrderWalk(SegmentTree->rightChild);
}

// Recursive procedure to find out the sum of elements
// from arr[low] to arr[high] using the Segment Tree
int getSumQuery(struct node * SegmentTree, int low, int high, int sum)
{
	if (low == SegmentTree->low && high == SegmentTree->high) {
		sum += SegmentTree->value;
		
		return sum;
	}
	
	if (low == high) {
		int mid = (SegmentTree->low + SegmentTree->high) / 2;
		
		if (low <= mid) {
			sum = getSumQuery(SegmentTree->leftChild, low, low, sum);
		} else {
			sum = getSumQuery(SegmentTree->rightChild, high, high, sum);
		}
	} else {
		int mid = (SegmentTree->low + SegmentTree->high) / 2;
		
		if (low <= mid && high > mid) {
			// Query range is partly in the left child and partly in the right child
			sum = getSumQuery(SegmentTree->leftChild, low, mid, sum);
			
			if (high >= mid + 1) {
				sum = getSumQuery(SegmentTree->rightChild, mid + 1, high, sum);
			}
		} else if (low <= mid && high <= mid) {
			// Query range is completely in the left Child
			sum = getSumQuery(SegmentTree->leftChild, low, high, sum);
		} else {
			// Query range is completely in the right child
			sum = getSumQuery(SegmentTree->rightChild, low, high, sum);
		}
	}
	
	return sum;
}

// Updates an element in the Segment Tree and makes the neccessary adjustments
int updateQuery(struct node * SegmentTree, int index, int newValue, int difference)
{
	if (SegmentTree->low == SegmentTree->high) {
		difference += newValue - SegmentTree->value;
		SegmentTree->value = newValue;
		
		return difference;
	}
	
	int mid = (SegmentTree->low + SegmentTree->high) / 2;
	
	if (index <= mid) {
		difference = updateQuery(SegmentTree->leftChild, index, newValue, difference);
	} else {
		difference = updateQuery(SegmentTree->rightChild, index, newValue, difference);
	}
	
	SegmentTree->value += difference;
	
	return difference;
}

int main()
{
	int n;
	
	printf("Enter the size of input -\n");
	scanf("%d", &n);
	
	int arr[n + 1], i;
	
	printf("\nEnter %d Integers -\n", n);
	
	arr[0] = -1;
	for (i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	struct node * SegmentTree = getSegmentTree(arr, n);
	
	// Printing the Tree after constructing
	printf("\nIn-Order Walk of the Segment Tree -\n");
	inOrderWalk(SegmentTree);
	
	int low, high;
	
	// Demonstrating Sum Query
	printf("\nEnter the range for sum query - [1, %d]\n", n);
	scanf("%d%d", &low, &high);	
	printf("\nSum = %d\n", getSumQuery(SegmentTree, low, high, 0));
	
	// Demonstrating Update Query
	printf("\nEnter the index of number and new value to update -\n");
	scanf("%d%d", &i, &low);
	updateQuery(SegmentTree, i, low, 0);
	
	// Printing the Tree after Updating
	printf("\nIn-Order Walk of the Segment Tree after Update -\n");
	inOrderWalk(SegmentTree);
	
	return 0;
}

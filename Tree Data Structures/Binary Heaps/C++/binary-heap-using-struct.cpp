/* ===== ===== =====

Theory of Programming

Binary Heap using structure and Heap Sort Algorithm
http://theoryofprogramming.com/2015/02/01/binary-heaps-and-heapsort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;

struct node
{
	int value;
	struct node * parent;
	struct node * leftChild;
	struct node * rightChild;
};

// Traverses the Heap top-to-bottom once and returns the location
// of the last node. Works on the priciple of traversing a
// Binary Tree by the binary representation of its size.
struct node * findLastNode(struct node * BinaryHeap, int size)
{
	list<int> Stack;
	
	// Getting the binary
	// representation of the size
	while (size != 0) {
		if (size & 1) {
			Stack.push_front(true);
		} else {
			Stack.push_front(false);
		}
		
		size = size >> 1;
	}
	
	// Omit the first bit
	Stack.pop_front();
	
	struct node * traverse = BinaryHeap;
	bool temp;
	
	while (Stack.size() != 0) {
		temp = Stack.front();
		Stack.pop_front();
		
		if (temp) {
			// encountered 1
			// go to rightChild
			traverse = traverse->rightChild;
		} else {
			// encountered 0
			// go to leftChild
			traverse = traverse->leftChild;
		}
	}
	
	return traverse;
}

// This makes the neccessary adjustments
// after insertion to ensure the validity
// of Heap Property in the Binary Heap
void bubbleUp(struct node * heap)
{
	if (heap->parent == NULL) {
		return;
	}
	
	if (heap->parent->value < heap->value) {
		// Swap child and parent
		int temp = heap->value;
		heap->value = heap->parent->value;
		heap->parent->value = temp;
		
		bubbleUp(heap->parent);
	}
}

// The recursive procedure which goes top-to-bottom from the root to the place of
// insertion and inserts the new node with a value 'Value'. Uses binary traversal.
struct node * insertUtil(struct node * BinaryHeap, int value, list<bool> * Stack)
{
	bool temp;
	
	if ((*Stack).size() == 1) {
		temp = (*Stack).front();
		(*Stack).pop_front();
		
		if (temp) {
			// create new node as the right child
			BinaryHeap->rightChild = (struct node *) calloc(1, sizeof(struct node));
			BinaryHeap->rightChild->parent = BinaryHeap;
			BinaryHeap = BinaryHeap->rightChild;
			BinaryHeap->value = value;
		} else {
			// create new node as the left child
			BinaryHeap->leftChild = (struct node *) calloc(1, sizeof(struct node));
			BinaryHeap->leftChild->parent = BinaryHeap;
			BinaryHeap = BinaryHeap->leftChild;
			BinaryHeap->value = value;
		}
	} else {
		temp = (*Stack).front();
		(*Stack).pop_front();
		
		if (temp) {
			// encountered 1
			// go to rightChild
			BinaryHeap = insertUtil(BinaryHeap->rightChild, value, Stack);
		} else {
			// encountered 0
			// go to leftChild
			BinaryHeap = insertUtil(BinaryHeap->leftChild, value, Stack);
		}
	}
	
	return BinaryHeap;
}

// Inserts a new node into the binary heap and also makes
// the neccessary swaps to ensure Heap Property isn't violated
void insertIntoHeap(struct node * BinaryHeap, int value, list<bool> * Stack)
{
	(*Stack).pop_front(); // Omit the first bit
	
	// Inserting into Heap and keeping a
	// track of the newly inserted node
	struct node * newNode = insertUtil(BinaryHeap, value, Stack);
	
	// Bubble the new node up the
	// Heap to ensure validity of
	// the Heap Property
	bubbleUp(newNode);
}

// Allocates memory for the Binary
// Heap thus creates the root node 
struct node * getBinaryHeap(int value)
{
	struct node * BinaryHeap = (struct node *) calloc(1, sizeof(struct node));
	
	BinaryHeap->value = value;
	
	return BinaryHeap;
}

// A simple utility function
// to aid In-Order Walk
void print(struct node * BinaryHeap)
{
	printf("%d ", BinaryHeap->value);
}

// Prints the nodes of the Binary
// Heap in the In-Order fashion
void inOrderTraversal(struct node * BinaryHeap)
{
	if (BinaryHeap == NULL) {
		return;
	}
	
	inOrderTraversal(BinaryHeap->leftChild);
	print(BinaryHeap);
	inOrderTraversal(BinaryHeap->rightChild);
}

// The standard recursive Heapify procedure to
// convert a partial heap to a complete heap
// Mainly used by Extract-Max procedure 
void heapify(struct node * BinaryHeap)
{
	if (BinaryHeap->leftChild != NULL && BinaryHeap->rightChild != NULL) {
		// both children exist
		
		if (BinaryHeap->value < BinaryHeap->leftChild->value && BinaryHeap->value < BinaryHeap->rightChild->value) {
			if (BinaryHeap->leftChild->value > BinaryHeap->rightChild->value) {
				// leftChild is greater
				
				int temp = BinaryHeap->value;
				BinaryHeap->value = BinaryHeap->leftChild->value;
				BinaryHeap->leftChild->value = temp;
				
				heapify(BinaryHeap->leftChild);
			} else {
				// rightChild is greater
				
				int temp = BinaryHeap->value;
				BinaryHeap->value = BinaryHeap->rightChild->value;
				BinaryHeap->rightChild->value = temp;
				
				heapify(BinaryHeap->rightChild);
			}
		} else if (BinaryHeap->value < BinaryHeap->leftChild->value && BinaryHeap->value > BinaryHeap->rightChild->value) {
			// leftChild is greater & rightChild is smaller than parent
				
			int temp = BinaryHeap->value;
			BinaryHeap->value = BinaryHeap->leftChild->value;
			BinaryHeap->leftChild->value = temp;
				
			heapify(BinaryHeap->leftChild);
		} else if (BinaryHeap->value > BinaryHeap->leftChild->value && BinaryHeap->value < BinaryHeap->rightChild->value) {
			// rightChild is greater & leftChild is smaller than parent
				
			int temp = BinaryHeap->value;
			BinaryHeap->value = BinaryHeap->rightChild->value;
			BinaryHeap->rightChild->value = temp;
				
			heapify(BinaryHeap->rightChild);
		}
	} else if (BinaryHeap->rightChild == NULL && BinaryHeap->leftChild != NULL) {
		// Only the leftChild exists
		
		if (BinaryHeap->leftChild->value > BinaryHeap->value) {
			// The existing leftChild is greater than parent
			// So swap
			
			int temp = BinaryHeap->leftChild->value;
			BinaryHeap->leftChild->value = BinaryHeap->value;
			BinaryHeap->value = temp;
		}
		
		// When we reach here, logically speaking, we have come
		// to the last node in the Binary Heap, so after this 
		// we simply return from the function
	}
}

// Returns the root value and deletes it by swapping the root
// node and the last node and then calling heapify on root node
int extractMax(struct node * BinaryHeap, struct node * lastNode)
{
	if (BinaryHeap == NULL) {
		return -1;
	}
	
	if (BinaryHeap == lastNode) {
		// A corner case where only
		// one node exists
		
		int max = BinaryHeap->value;
		
		free(BinaryHeap);
		
		return max;
	}
	
	int max = BinaryHeap->value;
	
	// Swap root node and last node
	int temp = BinaryHeap->value;
	BinaryHeap->value = lastNode->value;
	lastNode->value = temp;
	
	// Making its parent point to NULL appropriately
	struct node * parent = lastNode->parent;
	
	if (parent->leftChild == lastNode) {
		parent->leftChild = NULL;
	} else {
		parent->rightChild = NULL;
	}
	
	// Deleting the lastNode
	free(lastNode);
	heapify(BinaryHeap);	// making adjustments
	
	return max;
}

// Heap Sort procedure which takes and empyt list 'Sorted List'
// and fills it with the elements in sorted order. Keeps extracting
// the maximum element from the Max Heap until it is empty
void heapSort(struct node * BinaryHeap, list<int> * SortedList, int HeapSize)
{
	struct node * lastNode;
	list<int>::iterator itr;
	
	while (HeapSize != 0) {
		//getting the lastNode to assist extractMax procedure
		lastNode = findLastNode(BinaryHeap, HeapSize);
		(*SortedList).push_front(extractMax(BinaryHeap, lastNode));
		--HeapSize;
	}
}

int main()
{
	int n;
	
	printf("Enter the size of input -\n");
	scanf("%d", &n);
	
	int temp, i, j, HeapSize = 0;
	struct node * BinaryHeap;
	list<bool> Stack;
	
	printf("\nEnter %d integers -\n", n);
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &temp);
		++HeapSize;
		
		if (i == 0) {
			BinaryHeap = getBinaryHeap(temp);
			continue;
		}
		
		// Clears the Stack before filling it with
		// the Binary Representation of HeapSize
		Stack.clear();
		j = HeapSize;
		
		while (j != 0) {
			if (j & 1) {
				Stack.push_front(true);
			} else {
				Stack.push_front(false);
			}
			
			j = j >> 1;
		}
		
		insertIntoHeap(BinaryHeap, temp, &Stack);
	}
	
	printf("\nIn Order Traversal - ");
	inOrderTraversal(BinaryHeap);
	printf("\n");
	
	list<int> SortedList;
	
	heapSort(BinaryHeap, &SortedList, HeapSize);
	BinaryHeap = NULL;
	
	list<int>::iterator itr = SortedList.begin();
	
	printf("\nElements in Sorted order - ");
	while (itr != SortedList.end()) {
		printf("%d ", *itr);
		++itr;
	}
	printf("\n");
	
	return 0;
}

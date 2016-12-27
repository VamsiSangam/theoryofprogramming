/* ===== ===== =====

Theory of Programming

Quick sort algorithm with dual pivot
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Aditya Aggarwal (github.com/the-cybersapien, cybersapien.xyz)

===== ===== ===== */

import java.util.Scanner;

public class QuickSortDualPivot
{
	
	public static void main(String[] args) {
	// Initialize the Scanner Object to take input
        Scanner in = new Scanner(System.in);
        // Get the Size of the Array
        System.out.println("Enter the size of the array:");
        int size = in.nextInt();
        // Initialize the Array for sorting the elements
        int[] array = new int[size];
        // Get the data from user
        System.out.println("Enter the elements of the array: ");

        for (int i = 0; i < size; i++) {
            array[i] = in.nextInt();
        }

        // Sort the Array using Quick Sort
        quickSortDualPivot(array,0, size-1);
        
        // Print the final answer to the User:
        System.out.println("Sorted Array: ");
        
        for (int x : array){
            System.out.print(x + " ");
        }

        System.out.println();
    }

    public static void quickSortDualPivot(int[] array, int low, int high){
    	// Check if low is greater than high
    	// This is the break condition for the Recursive Solution
    	if (low >= high) {
    		return;
    	}

    	int lt = low + 1;
    	int ht = high - 1;

    	// Swap 'low' and 'high' if neccessary
    	if (array[low] > array[high]) {
    		int temp = array[low];
    		array[low] = array[high];
    		array[high] = temp;
    	}

    	// If only two elements are there
    	// the previous step made sure that they're already sorted
    	if (low + 1 == high) {
    		return;
    	}

    	for (int i = low + 1;i <= high; i++) {
    		if (i > ht) {
    			// Every value above this index
    			// will have a value > array[high]
    			break;
    		}

    		if (array[i] < array[low]) {
    			// array[i] < pivot1, so,
    			// it is placed in first sub-array
    			int temp = array[lt];
    			array[lt] = array[i];
    			array[i] = temp;
    			lt++;
    		} else if (array[i] > array[high]) {
    			// array[i] > pivot2, so,
    			// it is placed in the third sub-array
    			int temp = array[ht];
    			array[ht] = array[i];
    			array[i] = temp;
    			ht--;
    			i--;
    		}

    		// The value of array[i] that does not go to either
    		// of the cases, falls in the second sub-array
    	}

    	// Swapping the two-pivots to correct places
    	ht++;
    	int temp = array[ht];
    	array[ht] = array[high];
    	array[high] = temp;
    	lt--;
    	temp = array[lt];
    	array[lt] = array[low];
    	array[low] = temp;

    	// Recursively do the same to the sub-arrays
    	quickSortDualPivot(array, low, lt - 1);
    	quickSortDualPivot(array, lt + 1, ht - 1);
    	quickSortDualPivot(array, ht + 1, high);
    }
}

/* ===== ===== =====

Theory of Programming

Quick sort algorithm with Dijksrta's 3-way paritioning
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Aditya Aggarwal (github.com/the-cybersapien, cybersapien.xyz)

===== ===== ===== */

import java.util.Scanner;

public class QuickSortDijsktra{

	public static void main(String[] args) {
        //Initialize the Scanner Object to take input
        Scanner in = new Scanner(System.in);
        //Get the Size of the Array
        System.out.println("Enter the size of the array:");
        int size = in.nextInt();
        //Initialize the Array for sorting the elements
        int[] array = new int[size];
        //Get the data from user
        System.out.println("Enter the elements of the array: ");

        for (int i = 0; i < size; i++) {
            array[i] = in.nextInt();
        }

        //Call the quickSort function to sort the Array
        quickSortDijsktra(array, 0, size - 1);

        //Print the Sorted Array
        System.out.println("Sorted Array: ");

        for (int a : array) {
            System.out.print(a + " ");
        }

        System.out.println();
    }

    public static void quickSortDijsktra(int[] array, int low, int high){
    	//Break condition for the Recursive Code
    	if (low >= high) {
    		
    		return;
    	}

    	int lt = low;
    	int ht = high;
    	int pivot = array[low];

    	for (int i = low + 1; i <= high; i++) {
    		if (lt == ht) {
    			break;
    		}

    		if (array[i] < pivot) {
    			int swap = array[lt];
    			array[lt] = array[i];
    			array[i] = swap;

    			lt++;
    		} else if (array[i] > pivot) {
    			int swap = array[ht];
    			array[ht] = array[i];
    			array[i] = swap;

    			ht--;
    			i--;
    		}
    	}

    	quickSortDijsktra(array, low, lt);
    	quickSortDijsktra(array, ht + 1, high);
    }
}
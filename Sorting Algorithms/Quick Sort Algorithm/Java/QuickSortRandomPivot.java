/* ===== ===== =====

Theory of Programming

Quick sort algorithm with random pivot selection
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Aditya Aggarwal (github.com/the-cybersapien, cybersapien.xyz)

===== ===== ===== */

import java.util.Scanner;

public class QuickSortRandomPivot {

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

        // Call the quickSort function to sort the Array
        quickSortRandomPivot(array, 0, size - 1);

        // Print the Sorted Array
        System.out.println("Sorted Array: ");

        for (int a : array) {
            System.out.print(a + " ");
        }

        System.out.println();
    }

    private static void quickSortRandomPivot(int[] array, int low, int high){
        if (low >= high) {
            // A single element is
            // considered to be sorted
            return;
        }

        // Choose a random pivot using the random number generator
        // Additional brackets added here to ensure that there is no problems
        // while typecasting from double to int due to precedence
        int mid = (((int) (Math.random() * (high - low))) + low);

        // Put the pivot at the last
        int temp = array[mid];
        array[mid] = array[high];
        array[high] = temp;

        int pivot = array[high];
        int i = low;
        int j = high - 1;

        while (j >= i){
            if (array[j] < pivot && array[i] > pivot){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                i++;
                j--;
            } else if (array[j] < pivot && array[i] <= pivot){
                i++;
            } else if (array[j] >= pivot && array[i] > pivot){
                j--;
            } else if (array[j] >= pivot && array[i] <= pivot){
                i++;
                j--;
            }
        }

        // Bring the pivot back to its
        // appropriate place
        temp = array[i];
        array[i] = array[high];
        array[high] = temp;

        quickSortRandomPivot(array, low, i - 1);
        quickSortRandomPivot(array, i + 1, high);
    }
}
/* ===== ===== =====

Theory of Programming

Quick Sort Algorithm
http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Aditya Aggarwal (github.com/the-cybersapien, cybersapien.xyz)

===== ===== ===== */

import java.util.Scanner;

public class QuickSort{

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
        quickSort(array, 0, size - 1);

        //Print the Sorted Array
        System.out.println("Sorted Array: ");

        for (int a : array) {
            System.out.print(a + " ");
        }

        System.out.println();
    }

    public static void quickSort(int[] arr, int low, int high) {
        //Check if low is smaller than high
        //This is the exit condition for the recursive solution
        if (low < high){
        	//partition and swap the array
            int partitionIndex = partition(arr, low, high);
            //Quicksort the left of the partition
            quickSort(arr, low, partitionIndex - 1);
            //Quicksort the right of the partition
            quickSort(arr, partitionIndex + 1, high);
        }
    }

    private static int partition(int arr[], int low, int high){
        //Select the pivot as the highest element in the array
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }
}
import java.util.Scanner;

/* ===== ===== =====

Theory of Programming

Merge Sort Algorithm
http://theoryofprogramming.com/2015/01/29/merge-sort-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Aditya Aggarwal (github.com/the-cybersapien, cybersapien.xyz)

===== ===== ===== */
public class MergeSort
{

    public static void main(String[] args){
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

        // Sort the Array using Merge Sort
        mergeSort(array,0, size-1);
        
        // Print the final answer to the User:
        System.out.println("Sorted Array: ");
        
        for (int x : array){
            System.out.print(x + " ");
        }

        System.out.println();
    }

    private static void mergeSort(int array[], int low, int high){
        // Check if low is smaller than higher
        // this is the exit condition for the recursive solution
        if (low < high){
            
            // get the index of the element in the middle
            int mid = low + (high - low) / 2;
            
            // sort the left side of the array
            mergeSort(array, low, mid);
            // sort the right side of the array
            mergeSort(array, mid + 1, high);
            // Combine the two arrays
            merge(array, low, mid, high);
        }
    }

    private static void merge(int[] array, int low, int mid, int high) {
        int[] aux = new int[array.length];
        
        // Copy both parts into the auxiliary array
        for (int i = low; i <= high; i++){
            aux[i] = array[i];
        }

        int i = low;
        int j = mid + 1;
        int k = low;
        
        // Merge the left and right parts of the array while comparing their values
        while (i <= mid && j <= high){
            if (aux[i] <= aux[j]){
                array[k] = aux[i];
                i++;
            } else{
                array[k] = aux[j];
                j++;
            }
            k++;
        }
        

        while (i <= mid){
            array[k] = aux[i];
            k++;
            i++;
        }

    }
}

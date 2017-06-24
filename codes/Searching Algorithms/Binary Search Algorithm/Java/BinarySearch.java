/* ===== ===== =====

Theory of Programming

Binary Search Algorithm
http://theoryofprogramming.com/2016/11/04/binary-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Saurabh Rane (github.com/ranesr)

===== ===== ===== */

public class BinarySearch {

	private static int binarySearch(int arr[], int val) {
		if(arr == null || arr.length == 0) {
			return -1;
		}
		int low = 0;
	    int high = arr.length - 1;

	    while (low < high) {
	        int mid = low + (high - low) / 2;

	        if (arr[mid] == val) {
	            return mid;
	        } else if (arr[mid] < val) {
	            low = mid + 1;
	        } else {
	            high = mid - 1;
	        }
	    }

	    return arr[low] == val ? low : -1;
	}
	
	public static void main(String[] args) {
		int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int i;
		
		for (i = -1; i <= 10; ++i) {
			int index = binarySearch(arr, i);
			
			if (index != -1) {
				System.out.println(i + " found at index: " + index);
			} else {
				System.out.println(i + " not found");
			}
		}
	}
}
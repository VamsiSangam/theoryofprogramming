/* ===== ===== =====

Theory of Programming

Jump Search Algorithm
http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */
 
public class JumpSearch {
 
    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13, 15};
 
        System.out.println(jumpSearch(arr, 0)); // -1
        System.out.println(jumpSearch(arr, 3)); // 1
        System.out.println(jumpSearch(arr, 11)); // 5
        System.out.println(jumpSearch(arr, 16)); // -1
    }
 
    public static int jumpSearch(int[] arr, int val) {
        int jump = (int) Math.sqrt(arr.length);
        int left = 0;
        int right = 0;
 
        while (left < arr.length && arr[left] <= val) {
            right = Math.min(arr.length - 1, left + jump);
 
            if (arr[left] <= val && arr[right] >= val) {
                break;
            }
 
            left += jump;
        }
 
        if (left >= arr.length || arr[left] > val) {
            return -1;
        }
 
        right = Math.min(arr.length - 1, right);
 
        for (int i = left; i <= right && arr[i] <= val; ++i) {
            if (arr[i] == val) {
                return i;
            }
        }
 
        return -1;
    }
 
}
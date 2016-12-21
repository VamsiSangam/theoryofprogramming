/* ===== ===== =====

Theory of Programming

Optimised Jump Search Algorithm
http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */
 
public class OptimisedJumpSearch {
 
    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13, 15};
 
        System.out.println(jumpSearch(arr, 0)); // -1
        System.out.println(jumpSearch(arr, 3)); // 1
        System.out.println(jumpSearch(arr, 11)); // 5
        System.out.println(jumpSearch(arr, 16)); // -1
    }
 
    public static int jumpSearch(int[] arr, int val) {
        int low = 0, high = arr.length - 1;
 
        while (high - low > 1) {
            Pair p = jumpSearchUtil(arr, val, low, high);
 
            if (p == null) {
                return -1;
            }
 
            low = p.left;
            high = p.right;
        }
 
        return arr[low] == val ? low : arr[high] == val ? high : -1;
    }
 
    private static Pair jumpSearchUtil(int[] arr, int val, int low, int high) {
        int left = low;
        int step = (int) Math.sqrt(high - low);
        int right = 0;
 
        while (left < high && arr[left] <= val) {
            right = Math.min(left + step, high);
 
            if (arr[left] <= val && arr[right] >= val) {
                return new Pair(left, right);
            }
 
            left = right;
        }
 
        return null;
    }
 
}
 
class Pair {
    int left, right;
 
    public Pair(int left, int right) {
        this.left = left;
        this.right = right;
    }
}
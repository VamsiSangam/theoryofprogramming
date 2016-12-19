/* ===== ===== =====

Theory of Programming

Dynamic Programming - Kadane's Algorithm
http://theoryofprogramming.com/2016/10/21/dynamic-programming-kadanes-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

public class KadanesAlgorithm {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        
        for (int i = 0; i < n; ++i) {
            arr[i] = s.nextInt();
        }
        
        System.out.println(maxSubArray(arr));
    }
    
    public static int maxSubArray(int[] arr) {
        int maxSum, maxGlobalSum;
 
        maxSum = maxGlobalSum = arr[0];
 
        for (int i = 1; i < arr.length; ++i) {
            maxSum = arr[i] > arr[i] + maxSum ? arr[i] : arr[i] + maxSum;
            maxGlobalSum = maxSum > maxGlobalSum ? maxSum : maxGlobalSum;
        }
 
        return maxGlobalSum;
    }

}
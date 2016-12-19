/* ===== ===== =====

Theory of Programming

Edit Distance Algorithm
http://theoryofprogramming.com/2016/11/06/dynamic-programming-edit-distance/
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

public class OptimisedEditDistance {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        in.nextLine();
        
        while (t-- > 0) {
            String a = in.nextLine();
            String b = in.nextLine();
            
            System.out.println(editDistance(a, b));
        }
    }
     
    public static int editDistance(String a, String b) {
        if (a.length() < b.length()) {
            String temp = a;
            a = b;
            b = temp;
        }
         
        // b is the shorter string
        int[] prev = new int[b.length() + 1];
         
        for (int i = 0; i <= b.length(); ++i) {
            prev[i] = i;
        }
         
        int[] curr = new int[b.length() + 1];
         
        for (int i = 1; i <= a.length(); ++i) {
            curr[0] = i;
             
            for (int j = 1; j <= b.length(); ++j) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + Math.min(prev[j - 1],
                                  Math.min(prev[j], curr[j - 1]));
                }
            }
             
            for (int j = 0; j <= b.length(); ++j) {
                prev[j] = curr[j];
                curr[j] = 0;
            }
        }
         
        return prev[b.length()];
    }

}
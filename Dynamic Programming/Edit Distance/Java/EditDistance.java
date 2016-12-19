/* ===== ===== =====

Theory of Programming

Edit Distance Algorithm
http://theoryofprogramming.com/2016/11/06/dynamic-programming-edit-distance/
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

public class EditDistance {

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
        int[][] dp = new int[a.length() + 1][b.length() + 1];
         
        // Initialising first column
        for (int i = 0; i <= a.length(); ++i) {
            dp[i][0] = i;
        }
         
        // Initialising first row
        for (int j = 0; j <= b.length(); ++j) {
            dp[0][j] = j;
        }
         
        for (int i = 1; i <= a.length(); ++i) {
            for (int j = 1; j <= b.length(); ++j) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1],
                                   Math.min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
         
        return dp[a.length()][b.length()];
    }

}
/* ===== ===== =====

Theory of Programming

- Dynamic Programming - Rod Cutting
Github - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.HashMap;

public class RodCutting {

    public static void main(String[] args) {
        // price[0] is cost for length  = 0, for simiplicity
        int[] price = { 0, 1, 5, 8, 9, 10, 17, 17, 20 }; // price will be consumed as 1-indexed
        
        System.out.println("Max value of rod, computed by Memoisation approach = " + maxValueOfRod(price.length - 1, price, new HashMap<Integer, Integer>()));
        System.out.println("Max value of rod, computed by Bottom-up approach = " + maxValueOfRod(price.length - 1, price));
    }
    
    // Memoisation Version
    public static int maxValueOfRod(int n, int[] price, HashMap<Integer, Integer> cache)
    {
        if (n == 0)
        {
            return 0;
        }
        
        if( cache.containsKey(n) )
        {
            // maxValueOfRod(n) was already computed
            // return the stored value
            return cache.get(n);
        }
        
        int max = Integer.MIN_VALUE;
        
        for (int i = 1; i <= n; ++i)
        {
            max = Math.max(max, price[i] + maxValueOfRod(n - i, price, cache));
        }
        
        cache.put(n, max); // store maxValueOfRod(n) so that we don't compute it again
        
        // Uncomment below print statement to see in which order 'cache' gets filled
        // 'cache' will get filled in the exact same order as 'sol' used in the bottom-up approach
        // System.out.println("Computed maxValueOfRod(" + n + ")");
        
        return max;
    }
    
    // Bottom-up Version
    public static int maxValueOfRod(int n, int[] price)
    {
        int[] sol = new int[n + 1];
        
        sol[0] = 0;
        
        for (int i = 1; i <= n; ++i)
        {
            int max = Integer.MIN_VALUE;
            
            for (int j = 1; j <= i; ++j)
            {
                max = Math.max(max, price[j] + sol[i - j]);
            }
            
            sol[i] = max;
        }
        
        return sol[n];
    }

}

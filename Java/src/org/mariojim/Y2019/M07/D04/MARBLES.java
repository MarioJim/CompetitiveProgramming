package org.mariojim.Y2019.M07.D04;

import java.util.Scanner;

/**
 * MARBLES
 */
public class MARBLES {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        for (int i = 0; i < tests; i++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long top = factorial(n - 1, n - k);
            long bottom = factorial(k - 1, 1);
            long result = top / bottom;
            System.out.println(result);
        }
    }

    private static long factorial(int top, int bot) {
        long result = 1;
        for (int i = top; i > bot; i--)
            result *= i;
        return result;
    }
}

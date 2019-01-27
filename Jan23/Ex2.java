
// Greatest Common Divisor

import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums = { sc.nextInt(), sc.nextInt() };
        while (nums[0] != -1 && nums[1] != -1) {
            System.out.println(gcd(nums[0], nums[1]));
            nums[0] = sc.nextInt();
            nums[1] = sc.nextInt();
        }
        sc.close();
    }

    // Stein's Algorithm
    public static int gcd(int u, int v) {
        int twoPow = 0;
        if (u <= 1)
            return v;
        if (v <= 1)
            return u;
        for (; (u % 2 == 0) && (v % 2 == 0); ++twoPow) {
            u /= 2;
            v /= 2;
        }
        while (u % 2 == 0)
            u /= 2;
        do {
            while (v % 2 == 0)
                v /= 2;
            if (u > v) {
                int t = v;
                v = u;
                u = t;
            }
            v = v - u;
        } while (v != 0);
        return u * (int) Math.pow(2, twoPow);
    }
}
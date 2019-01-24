
// Not finished

import java.util.Scanner;

class Ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int[] nums = new int[3];

        sc.nextLine();
        for (int i = 0; i < t; i++) {
            String[] numsStr = sc.nextLine().split(" ");
            while (numsStr[0] != "-1" && numsStr[1] != "-1") {
                nums[0] = 1;
                nums[1] = Integer.parseInt(numsStr[0]);
                nums[2] = Integer.parseInt(numsStr[1]);

            }
        }
    }

    // Stein's Algorithm
    public static int[] gcd(int[] n) {
        if (n[1] == 1 || n[2] == 1 || n[1] == 0 || n[2] == 0)
            return n;
        else if (n[1] % 2 == 0 && n[2] % 2 == 0) {
            n[0] *= 2;
            n[1] /= 2;
            n[2] /= 2;
            return gcd(n);
        } else if (n[1] % 2 == 0) {
            n[1] /= 2;

        } else if (n[2] % 2 == 0) {
            n[2] /= 2;
        }
    }
}
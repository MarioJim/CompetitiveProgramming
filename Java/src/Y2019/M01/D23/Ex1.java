package Y2019.M01.D23;

import java.util.Scanner;

class Ex1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int x, sum, j;
        boolean canFinish;

        for (int i = 0; i < t; i++) {
            canFinish = true;
            sum = 1;
            j = 2;
            x = sc.nextInt();
            while ((x - sum) % j != 0 && canFinish) {
                if (sum > x)
                    canFinish = false;
                sum += j;
                j++;
            }
            System.out.println((canFinish) ? (x - sum) / j : "-1");
        }
        sc.close();
    }
}

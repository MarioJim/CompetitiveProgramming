package Y2019.M09.D04;

import java.util.Scanner;
import java.util.ArrayList;

/**
 * TPERML
 */
public class TPERML {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        for (int i = 0; i < tests; i++) {
            int n = sc.nextInt();
            int index = sc.nextInt();
            int m = sc.nextInt();
            System.out.println(parseToModifications(index, n));
        }
    }

    private static ArrayList<Integer> parseToModifications(int index, int n) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = index; i > 0; i--) {
            System.out.println(i);
            int fact = factorial(i);
            result.add(n / fact);
            n %= fact;
        }
        return result;
    }

    private static int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++)
            result *= i;
        return result;
    }
}

import java.util.Scanner;

public class Ex1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long x, result;

        for (int i = 0; i < t; i++) {
            x = sc.nextLong();
            result = 0;
            int j = 0;
            while (Math.pow(5, j) < x) {
                j++;
                result += x / Math.pow(5, j);
            }
            System.out.println(result);
        }
        sc.close();
    }
}
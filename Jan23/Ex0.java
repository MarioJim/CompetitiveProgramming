import java.util.Scanner;

public class Ex0 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long numer, denom, decimals, tempRes, res;

        for (int i = 0; i < t; i++) {
            numer = sc.nextInt();
            denom = sc.nextInt();
            decimals = sc.nextInt();
            res = 1;
            numer %= denom;
            for (int j = 0; j < decimals; j++) {
                numer *= 10;
                tempRes = numer / denom;
                res *= (tempRes == 0) ? 1 : tempRes;
                numer %= denom;
            }
            System.out.println(res);
        }
        sc.close();
    }
}
package org.mariojim.Y2019.M01.D30;

import java.util.Scanner;

public class Ex0part2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int numer, denom, decimals, periodMult, periodLength;
        long res;
        boolean[] foundMod;

        for (int i = 0; i < t; ++i) {
            numer = sc.nextInt();
            denom = sc.nextInt();
            decimals = sc.nextInt();
            numer %= denom;
            periodMult = 1;
            periodLength = 0;
            res = 1;
            foundMod = new boolean[denom];
            // Encontrar periodo en periodMult
            while (!foundMod[numer]) {
                foundMod[numer] = true;
                periodLength++;
                numer *= 10;
                periodMult *= (numer / denom == 0) ? 1 : numer / denom;
                periodMult %= 188888881;
                numer %= denom;
            }
            // Multiplicar resultado por periodo, int dec/longDePer veces
            for (int j = 0; j < decimals / periodLength; ++j) {
                res *= periodMult;
                res %= 188888881;
            }
            // Multiplicar resultado por periodo, dec%longDePer veces
            for (int j = 0; j < decimals % periodLength; ++j) {
                numer *= 10;
                res *= (numer / denom == 0) ? 1 : numer / denom;
                res %= 188888881;
                numer %= denom;
            }
            System.out.println(periodMult + ", " + periodLength);
            System.out.println(res);
        }
        sc.close();
    }
}

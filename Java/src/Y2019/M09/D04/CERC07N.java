package Y2019.M09.D04;

import java.util.Scanner;

/**
 * CERC07N
 */
public class CERC07N {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String string = sc.next();
        while (!string.equals("end")) {
            int input = sc.nextInt();
            if (string.startsWith("to")) {
                int base = Integer.parseInt(string.substring(2));
                System.out.println(Integer.toString(input, base));
            } else {
                int base = Integer.parseInt(string.substring(4));
                System.out.println(Integer.parseInt(String.valueOf(input), base));
            }
        }
    }
}

package Sep4;

import java.util.HashMap;
import java.util.Scanner;

/**
 * TCONNUM
 */
public class TCONNUM {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<Character, Integer> hashMap = genHashMap();
        int tests = sc.nextInt();
        for (int i = 0; i < tests; i++) {
            String input = sc.next();
            int baseFrom = sc.nextInt();
            int baseTo = sc.nextInt();
            long result = 0;
            int size = input.length();
            for (int j = 0; j < size; j++)
                result += Math.pow(baseFrom, j) * hashMap.get(input.charAt(j));

        }
    }

    private static HashMap<Character, Integer> genHashMap() {
        HashMap<Character, Integer> result = new HashMap<>();
        for (int i = 0; i < 10; i++)
            result.put(Integer.valueOf(i).toString().charAt(0), i);
        for (char i = 'A'; i <= 'Z'; i++)
            result.put(i, i - 'A' + 10);
        return result;
    }
}

import java.util.*;

public class Solution {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        System.out.println(solution(input));
        scanner.close();
    }

    private static String solution(String input) {
        StringBuilder x = new StringBuilder();
        for(char ch: input.toCharArray()) {
            switch(ch) {
                case 'A':
                    x.append('U');
                    break;
                case 'T':
                    x.append('A');
                    break;
                case 'C':
                    x.append('G');
                    break;
                case 'G':
                    x.append('C');
                    break;
                default:
                    ;
            }
        }
        return x.toString();
    }

}

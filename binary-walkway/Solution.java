import java.util.*;

public class Solution {
    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        StringBuilder builder = new StringBuilder();
        
        for(int i = 0; i < n; i++) {
            String s = scanner.next();
            builder.append((char)('1' + '0' - s.charAt(i)));
        }
        System.out.println(builder.toString());
        scanner.close();
    }
}

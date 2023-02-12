import java.util.*;

public class Solution {

    public static void main(String... args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        List<List<Integer> > list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            List<Integer> values = new ArrayList<>();
            for(int j = 0; j < 4; j++) {
                values.add(scanner.nextInt());
            }
            list.add(values);
        }
        System.out.println(solution(list));
        scanner.close();
    }

    private static long solution(List<List<Integer>> arr) {
        long max_bot = Integer.MIN_VALUE, min_top = Integer.MAX_VALUE, max_left = Integer.MIN_VALUE, min_right = Integer.MAX_VALUE;
        for(List<Integer> rec: arr) {
            long x_1 = rec.get(0), y_1 = rec.get(1), x_2 = rec.get(2), y_2 = rec.get(3);
            max_bot = Math.max(max_bot, y_1);
            min_top = Math.min(min_top, y_2);
            max_left = Math.max(max_left, x_1);
            min_right = Math.min(min_right, x_2);
        }
        if(max_bot < min_top && max_left < min_right) return (min_top - max_bot) * (min_right - max_left); else return 0;
    }

}

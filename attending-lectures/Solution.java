import java.util.*;

public class Solution {
    public static void main(String... args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        List<int[]> input = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            int a, b, c, d;
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            d = scanner.nextInt();
            input.add(new int[]{a, b, c, d});
        }
        scanner.close();
        System.out.println(solution(input));
    }

    public static int solution(List<int[]> binaryStrings) {
        int n = binaryStrings.size();
        int[][] dp = new int[n][1 << n];
        int[] pow = new int[n + 1];
        for(int i = 0; i <= n; i++) pow[i] = 1 << i;

        for(int i = 0; i < n; i++) {
            for(int mask = 0; mask < pow[n]; mask++) {
                dp[i][mask] = Integer.MIN_VALUE / 2;
            }
        }

        for(int i = 0; i < n; i++) {
            dp[i][1<<i] = binaryStrings.get(i)[0];
        }

        int[][] dist = new int[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = Math.abs(binaryStrings.get(i)[3] - binaryStrings.get(j)[3])
                    + Math.abs(binaryStrings.get(i)[2] - binaryStrings.get(j)[2]);
            }
        }

        for(int mask = 0; mask < pow[n]; mask ++) {
            for(int i = 0; i < n; i++) {
                if((mask & pow[i]) == 0) continue;
                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    if((mask & pow[j]) == 0) continue;
                    int new_mask = mask - pow[i];
                    dp[i][mask] = Math.max(dp[i][mask], dp[j][new_mask] + binaryStrings.get(i)[0] - dist[i][j] * binaryStrings.get(i)[1]);
                }
            }
        }

        int ans = Integer.MIN_VALUE;

        for(int i = 0; i < n; i++) {
            for(int mask = 0; mask < pow[n]; mask++) {
                ans = Math.max(ans, dp[i][mask]);
            }
        }
        return ans;
    }
}

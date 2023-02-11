import java.util.*;

public class Solution {
    public static void dfs(int node, ArrayList<Integer>[] edges, int[] color, int[] count) {
        count[color[node] - 1] ++;
        for(Integer k: edges[node]) {
            if(color[k] == 0) {
                color[k] = 3 - color[node];
                
                dfs(k,edges, color, count);
            }
        }
    }

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] edges = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++) edges[i] = new ArrayList<>();
        int[] color = new int[n + 1];
        Arrays.fill(color, 0);
        
        for(int i = 0; i < m; i++) {
            int a, b;
            a = scanner.nextInt();
            b = scanner.nextInt();
            edges[a].add(b);
            edges[b].add(a);
        }

        // System.out.println(Arrays.deepToString(edges));
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0) {
                int[] count = new int[]{0, 0};
                color[i] = 1;
                dfs(i, edges, color, count);
                ans += Math.max(count[0], count[1]);
            }
        }
        System.out.println(ans);
        return ;

    }
}

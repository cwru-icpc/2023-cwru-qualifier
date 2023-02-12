import java.util.*;

public class Solution {

    public static int[][] dir = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    public static void main(String... args) {

        Scanner scanner = new Scanner(System.in);

        int[][] board = new int[3][3];

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = scanner.nextInt();
            }
        }

        System.out.println(solution(encode(board)));
        scanner.close();

    }

    public static String encode(int[][] board) {
        StringBuilder builder = new StringBuilder();
        for(int[] row: board) {
            for(int e: row) {
                builder.append(e);
            }
        }
        return builder.toString();
    }

    public static int[][] decode(String str) {
        int[][] board = new int[3][3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = str.charAt(i * 3 + j) - '0';
            }
        }
        return board;
    }

    public static List<String> nextStates(String state) {
        List<String> states = new ArrayList<>();
        int[][] board = decode(state);
        int x = -1, y = -1;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }

        for(int o = 0; o < 4; o++) {
            int new_x = x + dir[o][0];
            int new_y = y + dir[o][1];
            if(new_x >= 0 && new_x < 3
            && new_y >= 0 && new_y < 3) {
                board[x][y] = board[new_x][new_y];
                board[new_x][new_y] = 0;
                states.add(encode(board));
                board[new_x][new_y] = board[x][y];
                board[x][y] = 0;
            }
        }
        return states;
    }

    public static int solution(String start) {
        String target = "123456780";
        Queue<String> queue = new LinkedList<>();
        Map<String, Integer> map = new HashMap<>();
        queue.offer(start);
        map.put(start, 0);
        while(!queue.isEmpty()) {
            String top = queue.poll();
            int dist = map.get(top);
            if(top.equals(target)) {
                break;
            }
            nextStates(top).stream().filter((e) -> !map.containsKey(e))
            .peek((e) -> map.put(e, dist + 1)).forEach((e) -> queue.offer(e));
        }
        // System.out.println(map);
        return map.getOrDefault(target, -1);
    }
    
}

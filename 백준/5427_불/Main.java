import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static String[] building;
    static int[][] fireCost;
    static int[][] exitCost;
    static int[] x = { 0, 1, 0, -1 };
    static int[] y = { -1, 0, 1, 0 };
    static int[] point;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());
        while (tc-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            building = new String[n];
            for (int i = 0; i < n; i++) {
                building[i] = br.readLine();
            }

            fireCost = new int[n][m];
            exitCost = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    fireCost[i][j] = exitCost[i][j] = n * m + 1;
                    if (building[i].charAt(j) == '@') {
                        point = new int[] { i, j };
                        exitCost[i][j] = 0;
                    }
                }
            }

            calFireCost();
            int ret = calExitCost();
            bw.write((ret == -1 ? "IMPOSSIBLE" : ret) + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

    private static boolean isRange(int y, int x) {
        return (0 <= y && y < n) && (0 <= x && x < m);
    }

    private static void calFireCost() {
        Queue<int[]> que = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (building[i].charAt(j) == '*') {
                    que.add(new int[] { i, j });
                    fireCost[i][j] = 0;
                }
            }
        }

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            for (int i = 0; i < 4; i++) {
                int[] next = { cur[0] + y[i], cur[1] + x[i] };
                if (!isRange(next[0], next[1]))
                    continue;
                if (building[next[0]].charAt(next[1]) == '#')
                    continue;
                if (fireCost[next[0]][next[1]] <= fireCost[cur[0]][cur[1]] + 1)
                    continue;
                fireCost[next[0]][next[1]] = fireCost[cur[0]][cur[1]] + 1;
                que.add(next);
            }
        }
    }

    private static int calExitCost() {
        Queue<int[]> que = new LinkedList<>();
        que.add(point);

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            for (int i = 0; i < 4; i++) {
                int[] next = { cur[0] + y[i], cur[1] + x[i] };
                if (!isRange(next[0], next[1]))
                    return exitCost[cur[0]][cur[1]] + 1;
                if (building[next[0]].charAt(next[1]) == '#')
                    continue;
                if (exitCost[next[0]][next[1]] <= exitCost[cur[0]][cur[1]] + 1)
                    continue;
                if (fireCost[next[0]][next[1]] <= exitCost[cur[0]][cur[1]] + 1)
                    continue;
                exitCost[next[0]][next[1]] = exitCost[cur[0]][cur[1]] + 1;
                que.add(next);
            }
        }
        return -1;
    }
}
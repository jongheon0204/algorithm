import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {
    private static int[][] iceberg;
    private static int[][] sea;
    private static int[] x = { 0, 1, 0, -1 };
    private static int[] y = { -1, 0, 1, 0 };

    private static boolean isDivided(int n, int m) {
        boolean[][] isVisit = new boolean[n][m];
        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (isVisit[i][j] || iceberg[i][j] == 0)
                    continue;
                if (++cnt > 1)
                    return true;
                Queue<int[]> que = new LinkedList<>();
                que.add(new int[] { i, j });
                isVisit[i][j] = true;
                while (!que.isEmpty()) {
                    int[] cur = que.poll();
                    for (int k = 0; k < 4; k++) {
                        int[] next = { cur[0] + y[k], cur[1] + x[k] };
                        if (iceberg[next[0]][next[1]] == 0 || isVisit[next[0]][next[1]])
                            continue;
                        isVisit[next[0]][next[1]] = true;
                        que.add(next);
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        iceberg = new int[n][m];
        sea = new int[n][m];

        for (int i = 0; i < n; i++) {
            iceberg[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        int ans = 0;
        while (true) {
            if (isDivided(n, m))
                break;

            int div = 10000;
            int num = 0;
            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    if (iceberg[i][j] == 0)
                        continue;
                    sea[i][j] = 0;
                    num++;
                    for (int k = 0; k < 4; k++) {
                        if (iceberg[i + y[k]][j + x[k]] == 0) {
                            sea[i][j]++;
                        }
                    }
                    if (sea[i][j] != 0) {
                        div = Math.min(div, iceberg[i][j] / sea[i][j] + (iceberg[i][j] % sea[i][j] != 0 ? 1 : 0));
                    }
                }
            }

            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    if (iceberg[i][j] == 0)
                        continue;
                    iceberg[i][j] -= sea[i][j] * div;
                    if (iceberg[i][j] <= 0) {
                        iceberg[i][j] = 0;
                        num--;
                    }
                }
            }

            if (num == 0) {
                ans = 0;
                break;
            }

            ans += div;
        }

        bw.write("" + ans);
        bw.flush();
        bw.close();
        br.close();
    }
}
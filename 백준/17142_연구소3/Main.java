import java.io.*;
import java.util.*;
import java.util.stream.Stream;

public class Main {
    private static int n;
    private static int m;
    private static int ans;
    private static int[][] laboratory;
    private static boolean[] isUse;
    private static int[] x = { 0, 1, 0, -1 };
    private static int[] y = { -1, 0, 1, 0 };
    private static List<int[]> virus = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ans = n * n + 1;
        laboratory = new int[n][n];

        for (int i = 0; i < n; i++) {
            laboratory[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < n; j++) {
                if (laboratory[i][j] == 2) {
                    virus.add(new int[] { i, j });
                }
            }
        }

        isUse = new boolean[virus.size()];
        minTime(0, 0);
        bw.write((ans == n * n + 1 ? -1 : ans) + "");

        bw.flush();
        bw.close();
        br.close();
    }

    private static void minTime(int depth, int cnt) {
        if (cnt == m) {
            spreadTime();
            return;
        }
        if (depth >= virus.size())
            return;

        isUse[depth] = true;
        minTime(depth + 1, cnt + 1);
        isUse[depth] = false;
        minTime(depth + 1, cnt);

    }

    private static void spreadTime() {
        int[][] time = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                time[i][j] = n * n + 1;
            }
        }
        Queue<int[]> que = new LinkedList<>();
        for (int i = 0; i < virus.size(); i++) {
            if (!isUse[i])
                continue;
            que.add(virus.get(i));
            time[virus.get(i)[0]][virus.get(i)[1]] = 0;
        }

        int maxVal = 0;
        while (!que.isEmpty()) {
            int[] cur = que.poll();
            if (laboratory[cur[0]][cur[1]] == 0) {
                maxVal = Math.max(maxVal, time[cur[0]][cur[1]]);
            }
            for (int i = 0; i < 4; i++) {
                int[] next = { cur[0] + y[i], cur[1] + x[i] };
                if (next[0] < 0 || next[1] < 0 || next[0] >= n || next[1] >= n)
                    continue;
                if (laboratory[next[0]][next[1]] == 1)
                    continue;
                int nextTime = time[cur[0]][cur[1]] + 1;
                if (time[next[0]][next[1]] > nextTime) {
                    time[next[0]][next[1]] = nextTime;
                    que.add(next);
                }
                if (laboratory[next[0]][next[1]] == 0 && time[next[0]][next[1]] >= ans)
                    return;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (laboratory[i][j] == 0 && time[i][j] > maxVal)
                    return;
            }
        }
        ans = Math.min(ans, maxVal);
    }
}
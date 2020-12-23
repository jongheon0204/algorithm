import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static int n;
    private static int k;
    private static int max;
    private static int[] cnt;
    private static int[] dis;
    private static Queue<int[]> que;

    private static void bfs(int idx, int val) {
        if (0 > idx || idx >= max || dis[idx] < val)
            return;
        if (dis[idx] == val)
            cnt[idx]++;
        else {
            dis[idx] = val;
            cnt[idx] = 1;
        }
        que.add(new int[] { idx, val });
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        if (n / 2 * 3 > k) {
            bw.write(Math.abs(n - k) + "\n" + 1);
        } else {
            max = (k / 2 + (k & 1)) * 3;

            cnt = new int[max];
            dis = new int[max];
            for (int i = 0; i < max; i++) {
                dis[i] = k;
            }

            que = new LinkedList<>();
            que.add(new int[] { n, 0 });
            dis[n] = 0;
            while (!que.isEmpty()) {
                int[] cur = que.poll();
                if (dis[cur[0]] < cur[1])
                    continue;
                bfs(cur[0] + 1, cur[1] + 1);
                bfs(cur[0] - 1, cur[1] + 1);
                bfs(cur[0] * 2, cur[1] + 1);
            }

            bw.write(dis[k] + "\n" + cnt[k]);
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
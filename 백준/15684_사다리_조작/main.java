import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static int n;
    private static int m;
    private static int h;
    private static boolean[][] ladder;

    private static boolean isLadder(int y, int d) {
        if (d == 0) {
            int[] num = new int[n];
            for (int i = 0; i < n; i++)
                num[i] = i;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < n; j++) {
                    if (ladder[i][j]) {
                        int t = num[j];
                        num[j] = num[j + 1];
                        num[j + 1] = t;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (num[i] != i)
                    return false;
            }
            return true;
        }

        for (int i = y; i < h; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (ladder[i][j] || ladder[i][j + 1])
                    continue;
                if (j != 0 && ladder[i][j - 1])
                    continue;
                ladder[i][j] = true;
                if (isLadder(i, d - 1))
                    return true;
                ladder[i][j] = false;
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        ladder = new boolean[h][n];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            ladder[a][b] = true;
        }

        int ans = -1;
        for (int i = 0; i < 4; i++) {
            if (isLadder(0, i)) {
                ans = i;
                break;
            }
        }

        bw.write("" + ans);

        bw.flush();
        bw.close();
        br.close();
    }
}
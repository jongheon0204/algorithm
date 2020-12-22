import java.io.*;
import java.util.*;

public class Main {
    private static int l;
    private static int r;
    private static int c;
    private static int[][][] dis;
    private static final int MAX_DIS = 27001;

    private static final int[] x = { 0, 1, 0, -1, 0, 0 };
    private static final int[] y = { -1, 0, 1, 0, 0, 0 };
    private static final int[] h = { 0, 0, 0, 0, 1, -1 };

    private static boolean isRange(int h, int y, int x) {
        return (0 <= h && h < l) && (0 <= y && y < r) && (0 <= x && x < c);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if (l == 0 && r == 0 && c == 0)
                break;

            int[] start = new int[] { -1, -1, -1 };
            int[] end = new int[] { -1, -1, -1 };

            dis = new int[l][r][c];
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < r; j++) {
                    String str = br.readLine();
                    for (int k = 0; k < c; k++) {
                        dis[i][j][k] = MAX_DIS;
                        if (str.charAt(k) == '#') {
                            dis[i][j][k] = -1;
                        } else if (str.charAt(k) == 'S') {
                            start = new int[] { i, j, k };
                            dis[i][j][k] = 0;
                        } else if (str.charAt(k) == 'E') {
                            end = new int[] { i, j, k };
                        }
                    }
                }
                br.readLine();
            }

            Queue<int[]> que = new LinkedList<>();
            que.add(start);
            dis[start[0]][start[1]][start[2]] = 0;
            while (!que.isEmpty()) {
                int[] cur = que.poll();
                for (int i = 0; i < 6; i++) {
                    int[] next = new int[] { cur[0] + h[i], cur[1] + y[i], cur[2] + x[i] };
                    if (!isRange(next[0], next[1], next[2]) || dis[next[0]][next[1]][next[2]] == -1)
                        continue;
                    if (dis[next[0]][next[1]][next[2]] <= dis[cur[0]][cur[1]][cur[2]] + 1)
                        continue;
                    dis[next[0]][next[1]][next[2]] = dis[cur[0]][cur[1]][cur[2]] + 1;
                    que.add(next);
                }
            }

            if (dis[end[0]][end[1]][end[2]] == MAX_DIS) {
                bw.write("Trapped!\n");
            } else {
                bw.write("Escaped in " + dis[end[0]][end[1]][end[2]] + " minute(s).\n");
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
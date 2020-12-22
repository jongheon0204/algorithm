import java.io.*;
import java.util.*;

public class Main {
    private static final int n = 12;
    private static final int m = 6;
    private static final int[] x = { 0, 1, 0, -1 };
    private static final int[] y = { -1, 0, 1, 0 };
    private static StringBuilder[] puyo = new StringBuilder[n];

    private static int puyoGame(int depth) {
        int ret = depth;
        int change = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (puyo[i].charAt(j) == '.')
                    continue;
                char comp = puyo[i].charAt(j);
                List<Integer[]> same = new ArrayList<>();
                Queue<Integer[]> que = new LinkedList<>();
                que.add(new Integer[] { i, j });
                change++;
                while (!que.isEmpty()) {
                    Integer[] cur = que.poll();
                    puyo[cur[0]].setCharAt(cur[1], '.');
                    same.add(cur);
                    for (int k = 0; k < 4; k++) {
                        Integer[] next = new Integer[] { cur[0] + y[k], cur[1] + x[k] };
                        if (0 > next[0] || 0 > next[1] || n <= next[0] || m <= next[1])
                            continue;
                        if (puyo[next[0]].charAt(next[1]) != comp)
                            continue;
                        que.add(next);
                    }
                }

                if (same.size() < 4) {
                    change--;
                    for (int k = 0; k < same.size(); k++) {
                        puyo[same.get(k)[0]].setCharAt(same.get(k)[1], comp);
                    }
                }
            }
        }

        if (change == 0)
            return ret;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int row = i;
                while (row <= n - 2 && puyo[row].charAt(j) != '.' && puyo[row + 1].charAt(j) == '.') {
                    puyo[row + 1].setCharAt(j, puyo[row].charAt(j));
                    puyo[row].setCharAt(j, '.');
                    row++;
                }
            }
        }

        return puyoGame(depth + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 0; i < n; i++) {
            puyo[i] = new StringBuilder(br.readLine());
        }

        bw.write("" + puyoGame(0));

        bw.flush();
        bw.close();
        br.close();
    }
}
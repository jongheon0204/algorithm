import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());
        while (tc-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int before = Integer.parseInt(st.nextToken());
            int after = Integer.parseInt(st.nextToken());

            boolean[] prime = new boolean[10000];
            IntStream.range(1000, 10000).forEach(i -> {
                int sqrtn = (int) Math.sqrt(i);
                prime[i] = IntStream.rangeClosed(2, sqrtn).noneMatch(j -> i % j == 0);
            });

            int[] distance = new int[10000];
            for (int i = 1000; i < 10000; i++) {
                distance[i] = 10000;
            }
            distance[before] = 0;

            Queue<Integer> que = new LinkedList<>();
            que.add(before);
            while (!que.isEmpty()) {
                int cur = que.poll();
                if (cur == after)
                    break;
                for (int i = 1; i <= 1000; i *= 10) {
                    for (int j = 0; j < 10; j++) {
                        int next = (cur / (i * 10) * (i * 10)) + (j * i) + (cur % i);
                        if (next < 1000 || next >= 10000)
                            continue;
                        if (distance[cur] + 1 < distance[next] && prime[next]) {
                            que.add(next);
                            distance[next] = distance[cur] + 1;
                        }
                    }
                }
            }
            bw.write((distance[after] == 10000 ? "Impossible" : "" + distance[after]) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
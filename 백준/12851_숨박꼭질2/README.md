### [12851. 숨박꼭질 2](https://www.acmicpc.net/problem/12851)

점 N에서 점 K로 이동하는데 걸리는 최소 시간과 이때 몇 가지 방법으로 갈 수 있는지 구하는 문제이다. 이때 이동은 X + 1, X - 1, 혹은 2 \* X의 위치로 이동할 수 있다.

이 문제는 BFS 방법을 통해 문제를 해결할 수 있다. 이때 방법의 수를 카운트 해야 하므로 이를 저장하는 별도의 배열을 생성 하는 것이 좋다.

```java
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
    private static int n;
    private static int k;
    private static int max;
    private static int [] cnt;
    private static int [] dis;
    private static Queue<int []> que;

    private static void bfs(int idx, int val){
        if(0 > idx || idx >= max || dis[idx] < val) return;
        if(dis[idx] == val) cnt[idx]++;
        else{
            dis[idx] = val;
            cnt[idx] = 1;
        }
        que.add(new int[]{idx, val});
    }

    public static void main(String [] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        if(n / 2 * 3 > k){
            bw.write(Math.abs(n - k) + "\n" + 1);
        }else {
            max = (k / 2 + (k & 1)) * 3;

            cnt = new int[max];
            dis = new int[max];
            for (int i = 0; i < max; i++) {
                dis[i] = k;
            }

            que = new LinkedList<>();
            que.add(new int[]{n, 0});
            dis[n] = 0;
            while (!que.isEmpty()) {
                int[] cur = que.poll();
                if (dis[cur[0]] < cur[1]) continue;
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
```

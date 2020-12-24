### [2573. 빙산](https://www.acmicpc.net/problem/2573)

n \* m 크기의 2차원 배열에 빙산의 크기가 양의 정수로 주어진다. 빙산은 동서남북으로 바닷물 수 만큼 크기가 줄어든다 할 때 하나의 빙산이 두 덩어리 이상으로 분리되는 최초의 시간을 구하는 문제이다.(모두 녹을 때 까지 분리되지 않으면 0을 출력)

빙산이 여러 덩어리로 나누어지는지 여부는 BFS를 사용하여 알아낼 수 있다. 이외에는 각 빙산의 주변에 바닷물 수 만큼 줄어드는 연산을 별도로 해야 한다.

```java
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main{
    private static int [][] iceberg;
    private static int [][] sea;
    private static int [] x = {0, 1, 0, -1};
    private static int [] y = {-1, 0, 1, 0};

    private static boolean isDivided(int n, int m){
        boolean [][] isVisit = new boolean[n][m];
        int cnt = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(isVisit[i][j] || iceberg[i][j] == 0) continue;
                if(++cnt > 1) return true;
                Queue<int []> que = new LinkedList<>();
                que.add(new int[]{i, j});
                isVisit[i][j] = true;
                while(!que.isEmpty()){
                    int [] cur = que.poll();
                    for(int k=0; k<4; k++){
                        int [] next = {cur[0] + y[k], cur[1] + x[k]};
                        if(iceberg[next[0]][next[1]] == 0 || isVisit[next[0]][next[1]]) continue;
                        isVisit[next[0]][next[1]] = true;
                        que.add(next);
                    }
                }
            }
        }
        return false;
    }

    public static void main(String [] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        iceberg = new int[n][m];
        sea = new int[n][m];

        for(int i=0; i<n; i++){
            iceberg[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        int ans = 0;
        while(true) {
            if(isDivided(n, m)) break;

            int div = 10000;
            int num = 0;
            for(int i=1; i<n-1; i++){
                for(int j=1; j<m-1; j++){
                    if(iceberg[i][j] == 0) continue;
                    sea[i][j] = 0;
                    num++;
                    for(int k=0; k<4; k++){
                        if(iceberg[i+y[k]][j+x[k]] == 0){
                            sea[i][j]++;
                        }
                    }
                    if(sea[i][j] != 0) {
                        div = Math.min(div, iceberg[i][j] / sea[i][j] + (iceberg[i][j] % sea[i][j] != 0 ? 1 : 0));
                    }
                }
            }

            for(int i=1; i<n-1; i++){
                for(int j=1; j<m-1; j++){
                    if(iceberg[i][j] == 0) continue;
                    iceberg[i][j] -= sea[i][j] * div;
                    if(iceberg[i][j] <= 0){
                        iceberg[i][j] = 0;
                        num--;
                    }
                }
            }

            if(num == 0){
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
```

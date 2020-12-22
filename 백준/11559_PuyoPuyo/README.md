### 11559. Puyo Puyo

12 \* 6 크기의 문자가 주어진다. 이때 상하좌우로 동일한 문자가 4개 이상 연결되어 있으면 문자를 제거할 수 있다고 할 때 최대 몇 번 제거할 수 있는지를 구하는 문제이다.

한 턴마다 BFS를 이용하여 제거할 수 있는 문자를 제거한 후 남은 문자열을 아래로 떨어뜨리는 방법을 사용하여 문제를 해결할 수 있다.

```java
import java.io.*;
import java.util.*;

public class Main{
    private static final int n = 12;
    private static final int m = 6;
    private static final int [] x = {0, 1, 0, -1};
    private static final int [] y = {-1, 0, 1, 0};
    private static StringBuilder [] puyo = new StringBuilder[n];

    private static int puyoGame(int depth) {
        int ret = depth;
        int change = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(puyo[i].charAt(j) == '.') continue;
                char comp = puyo[i].charAt(j);
                List<Integer []> same = new ArrayList<>();
                Queue<Integer []> que = new LinkedList<>();
                que.add(new Integer[]{i, j});
                change++;
                while(!que.isEmpty()){
                    Integer [] cur = que.poll();
                    puyo[cur[0]].setCharAt(cur[1], '.');
                    same.add(cur);
                    for(int k=0; k<4; k++){
                        Integer [] next = new Integer[]{cur[0] + y[k], cur[1] + x[k]};
                        if(0 > next[0] || 0 > next[1] || n <= next[0] || m <= next[1]) continue;
                        if(puyo[next[0]].charAt(next[1]) != comp) continue;
                        que.add(next);
                    }
                }

                if(same.size() < 4){
                    change--;
                    for(int k=0; k<same.size(); k++){
                        puyo[same.get(k)[0]].setCharAt(same.get(k)[1], comp);
                    }
                }
            }
        }

        if(change == 0) return ret;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                int row = i;
                while(row <= n-2 && puyo[row].charAt(j) != '.' && puyo[row+1].charAt(j) == '.'){
                    puyo[row+1].setCharAt(j, puyo[row].charAt(j));
                    puyo[row].setCharAt(j, '.');
                    row++;
                }
            }
        }

        return puyoGame(depth + 1);
    }

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<n; i++){
            puyo[i] = new StringBuilder(br.readLine());
        }

        bw.write("" + puyoGame(0));

        bw.flush();
        bw.close();
        br.close();
    }
}
```

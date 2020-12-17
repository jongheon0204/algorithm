### [9019. DSLR](https://www.acmicpc.net/problem/9019)

0 부터 9999까지 표현이 가능한 계산기가 있다. DSLR 명령어가 존재할 때 A에서 B 값을 만들기 위해 사용해야 하는 최소 명령어 개수를 구하는 문제이다.

Queue를 이용하여 각 명령어를 수행한 결과를 저장하여 문제를 해결할 수 있다.

```java
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
    private static final int MAX_VAL = 10000;

    private static int calculate(int val, int num){
        if(num == 0) return (val * 2) % MAX_VAL;
        else if(num == 1) return (val == 0 ? MAX_VAL : val) - 1;
        else if(num == 2) return (val % 1000) * 10 + (val / 1000);
        else return (val / 10) + (val % 10) * 1000;
    }

    public static void main(String [] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        while(tc-- != 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            String [] command = new String[MAX_VAL];
            String [] addCommand = {"D", "S", "L", "R"};
            int [] parent = new int[MAX_VAL];
            for(int i=0; i<MAX_VAL; i++) parent[i] = -1;

            Queue<Integer> que = new LinkedList<>();
            que.add(start);
            parent[start] = start;
            boolean isVisit = false;
            while(!que.isEmpty() && !isVisit){
                int cur = que.poll();
                if(cur == end) break;
                for(int i=0; i<4; i++){
                    int next = calculate(cur, i);
                    if(parent[next] == -1){
                        command[next] = addCommand[i];
                        parent[next] = cur;
                        que.add(next);
                        if(next == end) isVisit = true;
                    }
                }
            }

            StringBuilder ans = new StringBuilder();
            while(end != start){
                ans.append(command[end]);
                end = parent[end];
            }
            bw.write(ans.reverse().toString()+"\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
```

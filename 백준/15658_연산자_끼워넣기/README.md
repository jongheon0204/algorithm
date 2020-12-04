### [15658. 연산자 끼워넣기(2)](https://www.acmicpc.net/problem/15658)

N개의 숫자와 연산자의 개수가 주어질 때 수와 수 사이에 연산자를 넣어 만든 모든 수식들 중 최소 값과 최대 값을 구하는 문제이다.(이때 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행한다)

해당 문제는 DFS 방식을 통해 모든 경우의 수를 검사하는 방식으로 최소 값과 최대 값을 구할 수 있다.

```java
import java.io.*;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main{
    private static final int MAX_VAL = 1000000000;

    public static void dfs(int depth, int val, final List<Integer> values, List<Integer> opNum, List<Integer> ans){
        if(depth >= values.size()){
            ans.set(0, Math.min(ans.get(0), val));
            ans.set(1, Math.max(ans.get(1), val));
            return;
        }

				// 0 : '+', 1 : '-', 2 : '*', 3 : '/'
        for(int i=0; i<4; i++){
            if(opNum.get(i) == 0) continue;
            int cur = values.get(depth), t = val;
            if(i == 0) val += cur;
            else if(i == 1) val -= cur;
            else if(i == 2) val *= cur;
            else val /= cur;
            opNum.set(i, opNum.get(i) - 1);
            dfs(depth + 1, val, values, opNum, ans);
            opNum.set(i, opNum.get(i) + 1);
            val = t;
        }
    }

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        List<Integer> values = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());
        List<Integer> opNum = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());

        // Min 값, Max 값
        List<Integer> ans = Arrays.asList(MAX_VAL, -MAX_VAL);

        dfs(1, values.get(0), values, opNum, ans);
        bw.write("" + ans.get(1) + "\n" + ans.get(0));
        bw.flush();
        bw.close();
        br.close();
    }
}
```

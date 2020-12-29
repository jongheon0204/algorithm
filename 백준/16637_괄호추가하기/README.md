### [16637. 괄호 추가하기](https://www.acmicpc.net/problem/16637)

최대 길이 19인 수식이 주어진다. 연산자 우선순위가 모두 동일하다고 할 때 수식에 괄호를 적절하게 추가하여 얻을 수 있는 최대값을 구하는 문제이다.

괄호를 넣어 얻을 수 있는 모든 수식의 결과 값을 비교하여 문제를 해결할 수 있다.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    static int n;
    static String op;
    static boolean [] isUse;
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        op = br.readLine();
        isUse = new boolean[n / 2];
        System.out.print(dfs(1, op.charAt(0) - '0'));
        br.close();
    }

    private static int dfs(int depth, int val){
        if(depth > isUse.length) return val;
        int ret = Integer.MIN_VALUE;
        int pre = op.charAt(depth * 2) - '0';
        if((depth + 1 ) * 2 <= n){
            int next = op.charAt((depth + 1) * 2) - '0';
            int cal = calOp(pre, next, op.charAt(depth * 2 + 1));
            ret = Math.max(ret, dfs(depth + 2, calOp(val, cal, op.charAt(depth * 2 - 1))));
        }
        ret = Math.max(ret, dfs(depth + 1, calOp(val, pre, op.charAt(depth * 2 - 1))));
        return ret;
    }

    private static int calOp(int pre, int next, char p){
        if(p == '+') return pre + next;
        else if(p == '*') return pre * next;
        else return pre - next;
    }
}
```

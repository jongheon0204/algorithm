### [1918. 후위 표기식](https://www.acmicpc.net/problem/1918)

중위 표기식으로 되어 있는 수식을 후위 표기식으로 변경하는 문제이며 스택과 다음의 조건을 통해 문제를 해결할 수 있다.

1. 피연산자인 경우 결과 문자열에 추가한다.
2. ')'인 경우 '('에 나올때 까지 스택에서 pop연산을 한다.
3. 연산자인 경우 스택에 우선순위가 높거나 같은 기호들 전부 결과 문자열에 추가한다.

```java
import java.io.*;
import java.util.Stack;

public class Main{
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder ans = new StringBuilder();
        Stack<Character> sta = new Stack<>();

        String notation = br.readLine();
        for(int i=0, len = notation.length(); i<len; i++){
            char cur = notation.charAt(i);
            if('A' <= cur && cur <= 'Z'){
                ans.append(cur);
            }else if(cur == '('){
                sta.add(cur);
            }else if(cur == ')'){
                while(!sta.isEmpty()){
                    char next = sta.pop();
                    if(next == '(') break;
                    ans.append(next);
                }
            }else if(cur == '*' || cur == '/'){
                while(!sta.isEmpty() && (sta.peek() == '*' || sta.peek() == '/') && sta.peek() != '('){
                    ans.append(sta.pop());
                }
                sta.add(cur);
            }else{
                while(!sta.isEmpty() && sta.peek() != '('){
                    ans.append(sta.pop());
                }
                sta.add(cur);
            }
        }

        while(!sta.isEmpty()){
            ans.append(sta.pop());
        }

        bw.write(ans.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
```

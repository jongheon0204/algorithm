### [11723. 집합](https://www.acmicpc.net/problem/11723)

공집합 S에 대해 다음의 연산을 수행하는 프로그램을 만든다.

- `add x`: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
- `remove x`: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
- `check x`: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
- `toggle x`: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
- `all`: S를 {1, 2, ..., 20} 으로 바꾼다.
- `empty`: S를 공집합으로 바꾼다.

길이가 20인 Boolean 배열을 만든 후 명령어를 실행할 수 있다.

```java
import java.io.*;

public class Main{
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        boolean [] isContains = new boolean[21];
        while(n-- != 0){
            String [] cmd = br.readLine().split(" ");
            switch(cmd[0]){
                case "add":
                    isContains[Integer.parseInt(cmd[1])] = true;
                    break;
                case "remove":
                    isContains[Integer.parseInt(cmd[1])] = false;
                    break;
                case "check":
                    bw.write((isContains[Integer.parseInt(cmd[1])] ? "1\n" : "0\n"));
                    break;
                case "toggle":
                    int idx = Integer.parseInt(cmd[1]);
                    isContains[idx] = !isContains[idx];
                    break;
                case "all":
                    for(int i=1; i<=20; i++){
                        isContains[i] = true;
                    }
                    break;
                case "empty":
                    for(int i=1; i<=20; i++){
                        isContains[i] = false;
                    }
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
```

### [1747. 소수&팰린드롬](https://www.acmicpc.net/problem/1747)

특정 수 n이 주어질 때 n이상의 수 중 소수이면서 팰린드롬인 수를 구하는 문제이다.

n을 하나씩 증가시켜가며 팰린드롬인지 소수인지 확인하면 된다.

```java
import java.io.*;
import java.util.stream.IntStream;

public class Main{
    public static void main(String [] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()) - 1;
        while(++n != 0){
            String value = String.valueOf(n);
            boolean isPalin = IntStream.rangeClosed(0, value.length() / 2)
                    .allMatch(i -> value.charAt(i) == value.charAt(value.length() - i - 1));
            int sqrtn = (int) Math.sqrt(n);
            if(!isPalin) continue;
            final int t = n;
            boolean isPrime = IntStream.rangeClosed(2, sqrtn)
                    .noneMatch(i -> t % i == 0);
            if(isPrime && n != 1) break;
        }
        bw.write(""+n);

        bw.flush();
        bw.close();
        br.close();
    }
}
```

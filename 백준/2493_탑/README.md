### [2493. 탑](https://www.acmicpc.net/problem/2493)

n개의 서로 다른 높이의 탑이 존재한다. 각 탑은 왼쪽으로 레이저를 발사하며 발사한 탑보다 높이가 더 큰 탑에 전송이 된다고 할 때 각 탑에서 발사한 레이저는 몇번째 탐에 전송이 되는지 구하는 문제이다.

N은 최대 500,000이므로 하나씩 검사하게 된다면 시간 초과가 발생한다. 이를 방지하기 위해 한 탑에서 어디 탑으로 전송되는지를 저장하는 배열을 이용하여 중간에 존재하는 탑들을 검사하지 않아 시간을 줄일 수 있다.

```java
import java.io.*;
import java.util.Arrays;

public class Main{
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int [] tower = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int [] parent = new int[n];

        bw.write("0 ");
        for(int i=1; i<n; i++){
            int idx = i-1;
            while(idx != 0){
                if(tower[idx] > tower[i]) break;
                idx = parent[idx];
            }
            if(tower[idx] > tower[i]){
                bw.write(idx + 1 + " ");
                parent[i] = idx;
            }else{
                bw.write(idx+" ");
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
```

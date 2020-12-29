### [2263. 트리의 순회](https://www.acmicpc.net/problem/2263)

이진 트리의 인 오더, 포스트 오더가 주어질 때 프리오더를 구하는 문제이다.

트리의 루트가 포스트 오더에서는 맨 마지막에 나오며, 인 오더에서 루트를 기준으로 왼쪽은 왼쪽 자식 트리, 오른쪽은 오른쪽 자식 트리라는 점을 이용하여 문제를 해결할 수 있다.

```java
import java.io.*;
import java.util.stream.Stream;

public class Main{
    static int [] inOrder, postOrder, idx;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static void preOrder(int inStart, int inEnd, int postStart, int postEnd) throws IOException {
        if(inStart > inEnd || postStart > postEnd) return;
        int root = postOrder[postEnd];
        bw.write(root+" ");
        preOrder(inStart, idx[root] - 1, postStart, postStart + idx[root] - inStart - 1);
        preOrder(idx[root] + 1, inEnd, postStart + idx[root] - inStart, postEnd - 1);
    }

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        idx = new int[n+1];
        inOrder = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        postOrder = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for(int i=0; i<n; i++){
            idx[inOrder[i]] = i;
        }
        preOrder(0, n-1, 0, n-1);
        br.close();
        bw.flush();
        bw.close();
    }
}
```

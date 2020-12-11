### [1446A. Knapsack](https://codeforces.com/problemset/problem/1446/A)

n개의 물품 각각의 무게가 주어질 때 `W / 2 ≤ C ≤ W`를 만족하도록 몇 개를 골라내는 문제이다.

물품의 무게를 a라고 하였을 때 이 무게가 W보다 크다면 고를 수 없으며 W / 2 보다 크다면 해당 물품만 고르면 된다. 또한 W / 2 보다 작다면 해당 물품을 선택할 수 있는데 이때 이전 까지 고른 물품들의 무게가 W / 2 보다 작다면 a를 더하여도 W보다 작다는 점을 이용할 수 있다.

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        while(tc-- != 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long W =  Long.parseLong(st.nextToken());
            long half = (W / 2) + (W % 2 != 0? 1 : 0);
            long sum = 0;

            List<Integer> ans = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            for(int i=0; st.hasMoreTokens(); i++){
                int val = Integer.parseInt(st.nextToken());
                if(val > W) continue;
                sum += val;
                if(half <= val){
                    ans = Arrays.asList(i + 1);
                    break;
                }
                ans.add(i + 1);
                if(half <= sum) break;
            }

            if(sum < half){
                bw.write("-1\n");
            }else{
                bw.write("" + ans.size()+"\n");
                for(int idx : ans){
                    bw.write(idx+" ");
                }
                bw.write("\n");
            }

        }

        bw.flush();
        bw.close();
        br.close();
    }
}
```

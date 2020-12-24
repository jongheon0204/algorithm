### [16235. 나무 재테크](https://www.acmicpc.net/problem/16235)

N \* N 크기의 땅에 M개의 나무를 심은 후 봄, 여름, 가을, 겨울 각각 특정 조건에 따라 나무가 죽기도 하고 번식하기도 한다. 이때 K년 후 남은 나무의 개수를 구하는 문제이다.

해당 문제는 나이가 적은 나무가 먼저 양분을 소비하기 때문에 나이가 적은 나무가 앞에 나와야 한다. 배열을 사용하기에는 계속해서 정렬해야 하기 때문에 우선순위 큐를 사용하는 것이 좋다.

```java
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main{
    private static int [][] nutrient;
    private static int [][] addNutrient;
    private static PriorityQueue<Integer> [][] trees;
    private static final int [] x = {0, 1, 1, 1, 0, -1, -1, -1};
    private static final int [] y = {-1, -1, 0, 1, 1, 1, 0, -1};

    private static void springSummer(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                List<Integer> tree = new ArrayList<>();
                int deadTree = 0;
                while(!trees[i][j].isEmpty()){
                    int age = trees[i][j].poll();
                    if(age <= nutrient[i][j]){
                        nutrient[i][j] -= age;
                        tree.add(age + 1);
                    }else{
                        deadTree += age / 2;
                    }
                }
                for(int k=0; k<tree.size(); k++){
                    trees[i][j].add(tree.get(k));
                }
                nutrient[i][j] += deadTree;
            }
        }
    }

    private static void fallWinter(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                nutrient[i][j] += addNutrient[i][j];
                if(trees[i][j].isEmpty()) continue;
                int cnt = (int) trees[i][j].stream().filter(age -> age % 5 == 0).count();
                if(cnt == 0) continue;
                for(int k=0; k<8; k++){
                    int nextY = i + y[k];
                    int nextX = j + x[k];
                    if(0 > nextY || 0 > nextX || n <= nextY || n <= nextX) continue;
                    for(int p=0; p<cnt; p++){
                        trees[nextY][nextX].add(1);
                    }
                }
            }
        }
    }

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        nutrient = new int[n][n];
        addNutrient = new int[n][n];
        trees = new PriorityQueue[n][n];
        for(int i=0; i<n; i++){
            addNutrient[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for(int j=0; j<n; j++){
                nutrient[i][j] = 5;
                trees[i][j] = new PriorityQueue<>();
            }
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            trees[x][y].add(Integer.parseInt(st.nextToken()));
        }

        while(k-- != 0){
            springSummer(n);
            fallWinter(n);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans += trees[i][j].size();
            }
        }

        bw.write("" + ans);
        bw.flush();
        bw.close();
        br.close();
    }
}
```

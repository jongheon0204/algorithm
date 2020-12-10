### [풍선 터트리기](https://programmers.co.kr/learn/courses/30/lessons/68646?language=java)

서로 다른 숫자가 쓰여 있는 n개의 풍선이 있다. 풍선이 하나가 남을 때 까지 인접한 두 풍선 중 번호가 더 큰 풍선을 터트리며 번호가 더 작은 풍선을 터트리는 행위를 최대 1번 할 수 있다고 할때 최후까지 남을 수 있는 풍선의 개수를 구하는 문제이다.

인덱스가 i인 풍선은 왼쪽 풍선들 중 가장 작은 값, 오른쪽 풍선들 중 가장 작은 값을 비교하여 두 값들보다 크면 최후까지 남을 수 없다.

```java
class Solution {
    public int solution(int[] a) {
        if(a.length == 1) return 1;

        int ans = a.length;
        int [] cnt = new int[a.length];

        int left_min = a[0];
        int right_min = a[a.length - 1];

        for(int i=1; i<a.length - 1; i++){
            if(a[i] > left_min) cnt[i]++;
            else left_min = a[i];

            int idx = a.length - i -1;
            if(a[idx] > right_min) cnt[idx]++;
            else right_min = a[idx];
        }

        for(int i=0; i<a.length; i++){
            if(cnt[i] == 2) ans--;
        }

        return ans;
    }
}
```

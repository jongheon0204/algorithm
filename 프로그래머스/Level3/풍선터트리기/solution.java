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
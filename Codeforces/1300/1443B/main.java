import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String [] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());
        while(tc-- != 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            String building = br.readLine();
            int len = building.length();
            final int maxVal = (a + b) * len;
            // 0 : 밑에 광산이 없는 것, 1 : 밑에 광산이 있는 것
            int [][] dp = new int[len][2];
            for(int i = 0; i<len; i++){
                if(building.charAt(i) == '0'){
                    dp[i][0] = (i > 0 ? Math.min(dp[i-1][0], dp[i-1][1]) : 0);
                    dp[i][1] = (i > 0 ? Math.min(dp[i-1][0] + a + b, dp[i-1][1] + b) : (a + b));
                }else{
                    dp[i][0] = maxVal;
                    dp[i][1] = (i > 0 ? Math.min(dp[i-1][0] + a, dp[i-1][1]) : a);
                }
            }
            bw.write(Math.min(dp[len - 1][0], dp[len - 1][1])+"\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
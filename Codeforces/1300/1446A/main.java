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
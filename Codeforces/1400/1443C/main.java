import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        while (tc-- != 0) {
            int n = Integer.parseInt(br.readLine());

            int[] delivery = new int[n];
            int[] pickUp = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; st.hasMoreTokens(); i++) {
                delivery[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; st.hasMoreTokens(); i++) {
                pickUp[i] = Integer.parseInt(st.nextToken());
            }

            long left = 0;
            long right = 0;
            List<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (delivery[i] > pickUp[i]) {
                    idx.add(i);
                } else {
                    left = Math.max(left, delivery[i]);
                }
                right += pickUp[i];
            }

            long ans = right;
            while (left <= right) {
                long mid = (left + right) / 2;
                long sum = 0;
                for (Integer i : idx) {
                    if (delivery[i] > mid) {
                        sum += pickUp[i];
                    }
                }
                if (sum > mid) {
                    left = mid + 1;
                } else {
                    ans = Math.min(ans, mid);
                    right = mid - 1;
                }
            }

            bw.write("" + ans + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
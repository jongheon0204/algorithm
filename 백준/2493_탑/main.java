import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] tower = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] parent = new int[n];

        bw.write("0 ");
        for (int i = 1; i < n; i++) {
            int idx = i - 1;
            while (idx != 0) {
                if (tower[idx] > tower[i])
                    break;
                idx = parent[idx];
            }
            if (tower[idx] > tower[i]) {
                bw.write(idx + 1 + " ");
                parent[i] = idx;
            } else {
                bw.write(idx + " ");
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
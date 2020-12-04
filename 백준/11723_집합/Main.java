import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        boolean[] isContains = new boolean[21];
        while (n-- != 0) {
            String[] cmd = br.readLine().split(" ");
            switch (cmd[0]) {
                case "add":
                    isContains[Integer.parseInt(cmd[1])] = true;
                    break;
                case "remove":
                    isContains[Integer.parseInt(cmd[1])] = false;
                    break;
                case "check":
                    bw.write((isContains[Integer.parseInt(cmd[1])] ? "1\n" : "0\n"));
                    break;
                case "toggle":
                    int idx = Integer.parseInt(cmd[1]);
                    isContains[idx] = !isContains[idx];
                    break;
                case "all":
                    for (int i = 1; i <= 20; i++) {
                        isContains[i] = true;
                    }
                    break;
                case "empty":
                    for (int i = 1; i <= 20; i++) {
                        isContains[i] = false;
                    }
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
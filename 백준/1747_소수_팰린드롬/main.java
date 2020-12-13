import java.io.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()) - 1;
        while (++n != 0) {
            String value = String.valueOf(n);
            boolean isPalin = IntStream.rangeClosed(0, value.length() / 2)
                    .allMatch(i -> value.charAt(i) == value.charAt(value.length() - i - 1));
            int sqrtn = (int) Math.sqrt(n);
            if (!isPalin)
                continue;
            final int t = n;
            boolean isPrime = IntStream.rangeClosed(2, sqrtn).noneMatch(i -> t % i == 0);
            if (isPrime && n != 1)
                break;
        }
        bw.write("" + n);

        bw.flush();
        bw.close();
        br.close();
    }
}
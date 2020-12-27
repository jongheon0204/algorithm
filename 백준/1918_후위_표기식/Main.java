import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder ans = new StringBuilder();
        Stack<Character> sta = new Stack<>();

        String notation = br.readLine();
        for (int i = 0, len = notation.length(); i < len; i++) {
            char cur = notation.charAt(i);
            if ('A' <= cur && cur <= 'Z') {
                ans.append(cur);
            } else if (cur == '(') {
                sta.add(cur);
            } else if (cur == ')') {
                while (!sta.isEmpty()) {
                    char next = sta.pop();
                    if (next == '(')
                        break;
                    ans.append(next);
                }
            } else if (cur == '*' || cur == '/') {
                while (!sta.isEmpty() && (sta.peek() == '*' || sta.peek() == '/') && sta.peek() != '(') {
                    ans.append(sta.pop());
                }
                sta.add(cur);
            } else {
                while (!sta.isEmpty() && sta.peek() != '(') {
                    ans.append(sta.pop());
                }
                sta.add(cur);
            }
        }

        while (!sta.isEmpty()) {
            ans.append(sta.pop());
        }

        bw.write(ans.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
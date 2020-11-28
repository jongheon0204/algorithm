class Solution {

    public int solution(String[] lines) {
        int[] start = new int[lines.length];
        int[] end = new int[lines.length];

        for (int i = lines.length - 1; i >= 0; i--) {
            String[] date = lines[i].split(" ");

            String[] time = date[1].split(":");
            end[i] += Integer.parseInt(time[0]) * 3600 * 1000;
            end[i] += Integer.parseInt(time[1]) * 60 * 1000;

            String[] m = time[2].split("\\.");
            end[i] += Integer.parseInt(m[0]) * 1000;
            end[i] += Integer.parseInt(m[1]);

            start[i] = end[i];
            for (int j = 0, d = 1000, len = date[2].length(); j < len; j++) {
                if (date[2].charAt(j) == 's' || date[2].charAt(j) == '.') {
                    continue;
                }
                start[i] -= d * (date[2].charAt(j) - '0');
                d /= 10;
            }
            start[i]++;
        }

        int ans = 0;

        for (int i = 0; i < lines.length; i++) {
            int start_cnt = 0;
            int end_cnt = 0;

            for (int j = 0; j < lines.length; j++) {
                if (start[i] <= start[j] && start[j] < start[i] + 1000) {
                    start_cnt++;
                } else if (start[j] <= start[i] && start[i] <= end[j]) {
                    start_cnt++;
                }

                if (end[i] <= start[j] && start[j] < end[i] + 1000) {
                    end_cnt++;
                } else if (start[j] <= end[i] && end[i] <= end[j]) {
                    end_cnt++;
                }
            }

            ans = (start_cnt > ans ? start_cnt : ans);
            ans = (end_cnt > ans ? end_cnt : ans);
        }
        return ans;
    }
}
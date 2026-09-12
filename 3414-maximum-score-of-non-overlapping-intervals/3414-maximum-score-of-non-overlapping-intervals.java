import java.util.*;

class Solution {

    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();

        // [left, right, weight, originalIndex]
        int[][] a = new int[n][4];

        for (int i = 0; i < n; i++) {
            a[i][0] = intervals.get(i).get(0);
            a[i][1] = intervals.get(i).get(1);
            a[i][2] = intervals.get(i).get(2);
            a[i][3] = i;
        }

        // Sort by right endpoint
        Arrays.sort(a, (x, y) -> {
            if (x[1] != y[1]) return Integer.compare(x[1], y[1]);
            return Integer.compare(x[3], y[3]);
        });

        /*
         * prev[i] = largest index j < i such that
         * a[j].right < a[i].left
         */
        int[] ends = new int[n];
        for (int i = 0; i < n; i++) {
            ends[i] = a[i][1];
        }

        int[] prev = new int[n];

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (ends[mid] < a[i][0]) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            prev[i] = ans;
        }

        /*
         * dp[k][i] = best set using at most k intervals
         * among first i intervals.
         *
         * Store the actual indices so that ties can be
         * resolved lexicographically.
         */
        List<Integer>[][] dp = new ArrayList[5][n + 1];

        for (int k = 0; k <= 4; k++) {
            for (int i = 0; i <= n; i++) {
                dp[k][i] = new ArrayList<>();
            }
        }

        long[][] score = new long[5][n + 1];

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {

                // Option 1: don't take interval i-1
                score[k][i] = score[k][i - 1];
                dp[k][i] = new ArrayList<>(dp[k][i - 1]);

                // Option 2: take interval i-1
                int p = prev[i - 1] + 1;

                long takeScore =
                        a[i - 1][2] + score[k - 1][p];

                List<Integer> takeList =
                        new ArrayList<>(dp[k - 1][p]);

                takeList.add(a[i - 1][3]);

                Collections.sort(takeList);

                if (takeScore > score[k][i] ||
                    (takeScore == score[k][i]
                        && lexicographicallySmaller(takeList, dp[k][i]))) {

                    score[k][i] = takeScore;
                    dp[k][i] = takeList;
                }
            }
        }

        return dp[4][n].stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }

    private boolean lexicographicallySmaller(
            List<Integer> a,
            List<Integer> b) {

        int n = Math.min(a.size(), b.size());

        for (int i = 0; i < n; i++) {
            if (!a.get(i).equals(b.get(i))) {
                return a.get(i) < b.get(i);
            }
        }

        return a.size() < b.size();
    }
}
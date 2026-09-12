public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int result = guess(mid);

            if (result == 0) {
                return mid;
            } else if (result < 0) {
                // mid is higher than the picked number
                high = mid - 1;
            } else {
                // mid is lower than the picked number
                low = mid + 1;
            }
        }

        return -1;
    }
}
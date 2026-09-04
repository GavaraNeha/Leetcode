class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        int ans = INT_MAX;

        // First window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
        }

        ans = white;

        // Slide the window
        for (int i = k; i < blocks.size(); i++) {

            // Add the new block
            if (blocks[i] == 'W') {
                white++;
            }

            // Remove the old block
            if (blocks[i - k] == 'W') {
                white--;
            }

            ans = min(ans, white);
        }

        return ans;
    }
};
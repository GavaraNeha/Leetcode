class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> losses(100001, 0);
        vector<bool> played(100001, false);

        // Count losses and mark players who played
        for (auto match : matches) {
            int winner = match[0];
            int loser = match[1];

            played[winner] = true;
            played[loser] = true;

            losses[loser]++;
        }

        vector<int> zeroLoss;
        vector<int> oneLoss;

        // Check all players
        for (int player = 1; player <= 100000; player++) {
            if (played[player]) {
                if (losses[player] == 0) {
                    zeroLoss.push_back(player);
                }
                else if (losses[player] == 1) {
                    oneLoss.push_back(player);
                }
            }
        }

        return {zeroLoss, oneLoss};
    }
};
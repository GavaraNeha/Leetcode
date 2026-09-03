class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;

        // Find the current maximum
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }

        vector<bool> result;

        // Check each kid
        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};
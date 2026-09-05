class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;

        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int ans = 0;

        for (int i = 0; i < costs.size(); i++) {
            if (i < n)
                ans += costs[i][0];   // City A
            else
                ans += costs[i][1];   // City B
        }

        return ans;
    }
};
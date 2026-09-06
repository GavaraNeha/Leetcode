class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;

        function<void(int)> backtrack = [&](int start) {
            if (current.size() == k) {
                ans.push_back(current);
                return;
            }

            for (int i = start; i <= n; i++) {
                current.push_back(i);
                backtrack(i + 1);
                current.pop_back();
            }
        };

        backtrack(1);
        return ans;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> need;

        for (string w : words)
            need[w]++;

        int len = words[0].size();
        int total = len * words.size();

        for (int start = 0; start < len; start++) {
            int left = start, count = 0;
            unordered_map<string, int> have;

            for (int right = start; right + len <= s.size(); right += len) {
                string word = s.substr(right, len);

                if (need.count(word)) {
                    have[word]++;
                    count++;

                    while (have[word] > need[word]) {
                        string remove = s.substr(left, len);
                        have[remove]--;
                        left += len;
                        count--;
                    }

                    if (count == words.size()) {
                        ans.push_back(left);

                        string remove = s.substr(left, len);
                        have[remove]--;
                        left += len;
                        count--;
                    }
                } else {
                    have.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> char_counts(26, 0);

        for (char c : s) {
            char_counts[c - 'a']++;
        }

        for (char c : t) {
            char_counts[c - 'a']--;
        }

        for (int count : char_counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
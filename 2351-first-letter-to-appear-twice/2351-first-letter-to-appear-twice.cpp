class Solution {
public:
    char repeatedCharacter(string s) {
        bool seen[26] = {false};

        for (char c : s) {
            int index = c - 'a';

            if (seen[index]) {
                return c;
            }

            seen[index] = true;
        }

        return ' '; // won't happen because problem guarantees a repeat
    }
};
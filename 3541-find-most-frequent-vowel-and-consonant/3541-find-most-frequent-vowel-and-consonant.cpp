class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        // Find maximum frequency
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};
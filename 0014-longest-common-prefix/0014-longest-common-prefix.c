#include <string.h> // For strlen
#include <stdlib.h> // For malloc (if needed, but not strictly for this in-place modification)

char* longestCommonPrefix(char** strs, int strsSize) {
    // Handle edge cases
    if (strsSize == 0) {
        // Return an empty string. In C, you'd usually return a literal or an allocated empty string.
        // For LeetCode, "" is often handled by returning a pointer to a static empty string.
        // A common practice is to return strs[0] after modifying it to be empty, if strsSize >= 1.
        // If strsSize is 0, we can return a globally defined empty string or dynamically allocate.
        // For simplicity and common LeetCode patterns, let's assume if strsSize is 0,
        // returning a literal "" is acceptable, or the problem context implies strs will always have at least one string.
        // Let's create a static empty string for safety.
        static char empty_str[] = "";
        return empty_str;
    }

    // If there's only one string, it's the common prefix
    if (strsSize == 1) {
        return strs[0];
    }

    // Start with the first string as the initial common prefix candidate
    char* prefix = strs[0];
    int prefix_len = strlen(prefix);

    // Iterate through the rest of the strings
    for (int i = 1; i < strsSize; i++) {
        char* current_str = strs[i];
        int current_str_len = strlen(current_str);

        int j = 0; // Index for comparing characters

        // Compare characters until a mismatch or end of either string is reached
        while (j < prefix_len && j < current_str_len && prefix[j] == current_str[j]) {
            j++;
        }

        // If no common characters were found (j is 0), there's no common prefix
        if (j == 0) {
            static char empty_str[] = ""; // If no common prefix, set prefix to empty
            return empty_str;
        }

        // Truncate the prefix to the length of the common part found (j)
        prefix[j] = '\0';
        prefix_len = j; // Update the effective length of the prefix
    }

    return prefix;
}
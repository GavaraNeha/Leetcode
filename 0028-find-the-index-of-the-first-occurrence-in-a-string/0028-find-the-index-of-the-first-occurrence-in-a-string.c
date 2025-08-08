#include <string.h> // For strlen

int strStr(char* haystack, char* needle) {
    int n = strlen(haystack);
    int m = strlen(needle);

    // Handle trivial cases
    if (m == 0) { // According to constraints, m >= 1, but good practice for general case.
        return 0;
    }
    if (m > n) {
        return -1;
    }

    // Iterate through all possible starting positions in haystack
    for (int i = 0; i <= n - m; i++) {
        // Assume a match initially for the current starting position 'i'
        bool match = true; 
        
        // Compare needle with the substring of haystack starting at 'i'
        for (int j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                match = false; // Mismatch found
                break;         // No need to check further for this 'i', move to next
            }
        }

        // If the inner loop completed without a mismatch, we found the first occurrence
        if (match) {
            return i;
        }
    }

    // If the outer loop completes, needle was not found in haystack
    return -1;
}
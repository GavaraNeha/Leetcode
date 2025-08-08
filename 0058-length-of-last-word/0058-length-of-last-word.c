#include <string.h> // For strlen

int lengthOfLastWord(char* s) {
    int length = 0;
    int n = strlen(s); // Get the length of the string

    // Iterate from the end of the string backwards
    // We are looking for the first non-space character from the right.
    // Once we find it, we count characters until we hit a space or the beginning of the string.
    
    // Skip trailing spaces
    int i = n - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Now 'i' points to the last non-space character (or -1 if string was all spaces or empty,
    // though constraints say at least one word).
    // Start counting the length of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
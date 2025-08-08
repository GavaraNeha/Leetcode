#include <string.h> // For strlen
#include <stdio.h>  // For potential debugging (optional)

// Helper function to get the integer value of a Roman numeral character
int romanCharToInt(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; // Should not happen for valid Roman numerals
    }
}

int romanToInt(char* s) {
    int total = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        int currentVal = romanCharToInt(s[i]);

        // Check if there's a next character
        if (i + 1 < length) {
            int nextVal = romanCharToInt(s[i+1]);

            // If current value is less than the next, it's a subtractive case
            if (currentVal < nextVal) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        } else {
            // Last character, always add its value
            total += currentVal;
        }
    }
    return total;
}
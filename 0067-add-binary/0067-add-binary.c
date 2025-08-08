#include <string.h> // For strlen
#include <stdlib.h> // For malloc

// Helper to get max of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    // The maximum possible length of the sum is max(len_a, len_b) + 1 (for potential carry)
    // Plus 1 for the null terminator.
    int max_sum_len = max(len_a, len_b) + 1;
    char* result = (char*)malloc(sizeof(char) * (max_sum_len + 1));
    
    // Check for malloc failure (good practice)
    if (result == NULL) {
        return NULL; 
    }

    // Initialize the result array with null terminator at the very end
    result[max_sum_len] = '\0';

    int i = len_a - 1; // Pointer for string a (from right to left)
    int j = len_b - 1; // Pointer for string b (from right to left)
    int k = max_sum_len - 1; // Pointer for result string (from right to left)
    int carry = 0;

    // Loop until both strings are processed and there's no carry
    while (i >= 0 || j >= 0 || carry == 1) {
        int bit_a = (i >= 0) ? (a[i] - '0') : 0; // Convert char to int, or 0 if out of bounds
        int bit_b = (j >= 0) ? (b[j] - '0') : 0; // Convert char to int, or 0 if out of bounds

        int sum_bits = bit_a + bit_b + carry;

        result[k] = (sum_bits % 2) + '0'; // Current bit is sum % 2, convert back to char
        carry = sum_bits / 2;             // New carry is sum / 2

        // Move to the next digits (leftwards)
        i--;
        j--;
        k--;
    }

    // After the loop, if k is -1, it means there was a leading carry which filled result[0].
    // If k is 0, it means result[0] was also filled.
    // In both cases, the entire `result` array (from index 0) is valid.
    // If k is greater than 0, it means there was no final carry and `result[0...k-1]` are unused.
    // The actual sum starts from `result[k]`.
    
    return result + (k + 1); // This effectively skips leading unused zeros.
                             // E.g., if k is 0, result + 1 is the result,
                             // if k is -1 (means result[0] was filled), then result + 0 (result itself)
}
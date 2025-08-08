#include <stdbool.h> // Required for bool type

bool isPalindrome(int x) {
    // Edge cases:
    // 1. Negative numbers are not palindromes. For example, -121 reads 121- backwards.
    // 2. If the number ends in 0 (e.g., 10, 120), it can only be a palindrome if the number itself is 0.
    //    This is because if it ends in 0, for it to be a palindrome, it must also start with 0, which is only possible for the number 0.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;

    // We build the reversed number only for its second half.
    // The loop continues as long as the original number 'x' is greater than 'reversedHalf'.
    // When 'reversedHalf' becomes greater than or equal to 'x', we have processed roughly half the digits.
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + (x % 10); // Append the last digit of x to reversedHalf
        x /= 10;                                     // Remove the last digit from x
    }

    // At this point, there are two possible scenarios:
    // 1. The original number had an even number of digits:
    //    In this case, after the loop, 'x' will be equal to 'reversedHalf'.
    //    Example: x = 1221.
    //    - Iter 1: x = 122, reversedHalf = 1
    //    - Iter 2: x = 12, reversedHalf = 12
    //    Loop terminates because x (12) is not > reversedHalf (12).
    //    Here, x == reversedHalf (12 == 12) is true.

    // 2. The original number had an odd number of digits:
    //    In this case, after the loop, 'x' will contain the middle digit, and 'reversedHalf'
    //    will have one extra digit (the middle digit). To compare, we need to remove the
    //    middle digit from 'reversedHalf' by dividing it by 10.
    //    Example: x = 12321.
    //    - Iter 1: x = 1232, reversedHalf = 1
    //    - Iter 2: x = 123, reversedHalf = 12
    //    - Iter 3: x = 12, reversedHalf = 123
    //    Loop terminates because x (12) is not > reversedHalf (123).
    //    Here, x (12) is equal to reversedHalf / 10 (123 / 10 = 12).

    return x == reversedHalf || x == reversedHalf / 10;
}
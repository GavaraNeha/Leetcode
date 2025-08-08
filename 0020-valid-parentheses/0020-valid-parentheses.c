#include <stdbool.h> // For true/false
#include <string.h>  // For strlen
#include <stdlib.h>  // For malloc and free (if using dynamic stack)

// A simple stack implementation using a fixed-size array
// Constraints say s.length <= 10^4, so a stack of this size is sufficient.
#define MAX_STACK_SIZE 10001 // Max length + 1 for safety

char stack[MAX_STACK_SIZE];
int top = -1; // -1 indicates an empty stack

void push(char c) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = c;
    }
    // In a real-world scenario, you'd handle stack overflow.
    // For this problem's constraints, it won't happen if MAX_STACK_SIZE is sufficient.
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0'; // Or some indicator of error/empty stack
}

bool isEmpty() {
    return top == -1;
}

bool isValid(char* s) {
    // Reset the stack for each new call to isValid
    top = -1; 

    int len = strlen(s);
    if (len == 0) {
        return true; // Empty string is considered valid
    }

    for (int i = 0; i < len; i++) {
        char currentChar = s[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(currentChar);
        } else { // It's a closing bracket
            if (isEmpty()) {
                return false; // Closing bracket without a matching open bracket
            }

            char poppedChar = pop();
            if ((currentChar == ')' && poppedChar != '(') ||
                (currentChar == '}' && poppedChar != '{') ||
                (currentChar == ']' && poppedChar != '[')) {
                return false; // Mismatched bracket type
            }
        }
    }

    // After iterating through the string, if the stack is empty, all brackets were matched.
    return isEmpty();
}
class Solution {
    public String removeDuplicates(String s) {
        StringBuilder stack = new StringBuilder();

        for (char c : s.toCharArray()) {
            // If the top of stack is same as current character
            if (stack.length() > 0 && stack.charAt(stack.length() - 1) == c) {
                // Remove the duplicate
                stack.deleteCharAt(stack.length() - 1);
            } else {
                // Add character to stack
                stack.append(c);
            }
        }

        return stack.toString();
    }
}
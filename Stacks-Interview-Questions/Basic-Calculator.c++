/*

Leetcode : 224(Hard)

Intuition:
This problem requires implementing a basic calculator that supports the operators `+` and `-`, and parentheses `()`.

We can solve this problem using a **stack** to handle nested parentheses and intermediate results. When a closing parenthesis is encountered, the stack allows us to evaluate the expression inside the parentheses and apply the appropriate signs and numbers.
- We scan the string one character at a time.
- Numbers are accumulated and added to the result based on the current sign (`+` or `-`).
- Parentheses are handled by saving the current result and sign on the stack and resetting for the new expression within the parentheses.
  
Time Complexity: O(n)
- Each character in the string is processed once.

Space Complexity: O(n)
- We use a stack to store intermediate results and signs, so the space complexity depends on the depth of nested parentheses in the input string.

*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;  // Stack to store intermediate results and signs
        int result = 0; // This will store the final result
        int num = 0;    // Current number being processed
        int sign = 1;   // Sign of the current number, 1 for positive, -1 for negative

        // Traverse through each character in the string
        for (char &ch : s) {
            // If the current character is a digit, accumulate the number
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } 
            // If we encounter a plus sign, add the previous number with the appropriate sign
            else if (ch == '+') {
                result += sign * num;
                num = 0;   // Reset the number for the next one
                sign = 1;  // Set sign to positive for the next number
            } 
            // If we encounter a minus sign, add the previous number with the appropriate sign
            else if (ch == '-') {
                result += sign * num;
                num = 0;   // Reset the number for the next one
                sign = -1; // Set sign to negative for the next number
            } 
            // If we encounter an opening parenthesis, push the current result and sign onto the stack
            else if (ch == '(') {
                st.push(result);   // Save the current result
                st.push(sign);     // Save the current sign
                result = 0;        // Reset result for the new expression inside parentheses
                sign = 1;          // Default sign inside parentheses is positive
            } 
            // If we encounter a closing parenthesis, first process the last number
            else if (ch == ')') {
                result += sign * num;  // Process the last number before closing the parentheses
                num = 0;               // Reset number

                // Pop the sign and apply it to the result inside the parentheses
                result *= st.top(); // Multiply by the sign before the parentheses
                st.pop();

                // Pop the result before the parentheses and add it to the current result
                result += st.top(); // Add the result before the parentheses
                st.pop();
            }
        }

        // Add the last number to the result
        result += sign * num;
        return result;
    }
};

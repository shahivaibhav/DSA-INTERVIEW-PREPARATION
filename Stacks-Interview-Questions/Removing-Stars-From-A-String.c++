/*

    Remove Stars from a String (LeetCode 2390)(Medium)

    Input: s = "leet**code*", Output: "lecoe".
    Input: s = "erase*****", Output: "".

    Input String: The function takes an input string s containing alphabets and stars (*). Every star removes the character immediately before it.

    Stack Usage:

    A stack (st) is used to store characters in the string as we encounter them.
    When a star is encountered (*), it removes (pops) the top character from the stack, mimicking the "undo" effect of the star.
    Iterating Over the String:

    We traverse through the string one character at a time using a while loop.
    If the character is not a *, it is pushed onto the stack.
    If the character is a *, we pop the most recent character from the stack (if the stack isn't empty).
    Building the Result:

    After processing all characters in the string, the stack contains the valid characters in reverse order.
    We pop characters from the stack and build the result string (ans) in reverse order, then reverse the string to get the correct order.
    Final Output: The result is the string without stars and the characters they cancel.

    Time Complexity:
    O(n): We traverse the string once, and each operation (push/pop) takes constant time.
    Space Complexity:
    O(n): The stack stores at most n characters (in the worst case where there are no * characters).

*/

class Solution {
public:
    // Function to remove stars and the characters they cancel
    string removeStars(string s) {
        // Stack to store characters from the string that are not cancelled by '*'
        stack<char> st;
        int n = s.length();  // Length of the input string
        int i = 0;  // Pointer to iterate through the string

        // Traverse the string
        while( i < n ) {
            // If the current character is not a star, push it onto the stack
            if(s[i] != '*') {
                st.push(s[i]);
            }
            // If it's a star, pop the last character from the stack
            // Only pop if the stack is not empty
            else if(!st.empty() && s[i] == '*') {
                st.pop();
            }
            // Move to the next character
            i++;
        }

        // Prepare the resulting string from the stack
        string ans = "";

        // The stack contains the valid characters in reverse order, so we need to pop them
        while(!st.empty()) {
            ans += st.top();  // Append the top character of the stack to the result
            st.pop();  // Remove the top character from the stack
        }

        // Reverse the string since the stack stores characters in reverse order
        reverse(ans.begin(), ans.end());

        // Return the final result
        return ans;
    }
};

/*

Valid Parentheses (LeetCode 20)(Easy)

Problem:

Given a string s containing just the characters (, ), {, }, [ and ], determine if the input string is valid.

Solution Explanation: We use a stack to ensure that every opening bracket has a corresponding closing bracket in the correct order.

Time Complexity:

O(n): We process each character in the string once.

Space Complexity:
O(n): The stack can store up to n characters in the worst case.



*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets

        int n = s.length();  // Length of the string
        int i = 0;

        // Loop through the string
        while(i < n) {

            // If current character is a closing bracket and matches the top of the stack, pop the stack
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if(!st.empty() && st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else if(!st.empty() && st.top() == '[' && s[i] == ']'){
                st.pop();
            }
            else {
                // Push opening brackets onto the stack
                st.push(s[i]);
            }
            i++;
        }

        // If stack is empty, all brackets are balanced
        return st.empty();
    }
};

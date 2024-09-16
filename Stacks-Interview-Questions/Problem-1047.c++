/*
Intuition:
The problem asks to remove adjacent duplicates from a string. A **stack** is the perfect data structure for this task because it follows a **Last In, First Out (LIFO)** order, which allows us to easily check the most recently added character and compare it with the current one.
- As we iterate through the string, if the current character is the same as the one on top of the stack, it means they are duplicates, so we remove (pop) the top character.
- If the current character is different, we push it onto the stack.
- After processing the string, the stack will contain only the characters that are not duplicates.

Time Complexity: O(n)
- We traverse the string once, and each character is pushed and popped from the stack at most once, leading to a linear time complexity.

Space Complexity: O(n)
- In the worst case, if there are no duplicates, we store all the characters in the stack, so the space complexity is proportional to the input size.
*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;  // Stack to keep track of characters

        // Loop through each character in the string
        for(auto &ch : s){
            // If the stack is not empty and the top character is the same as the current one, pop it
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            // Otherwise, push the current character onto the stack
            else{
                st.push(ch);
            }
        }

        // Create an empty string to store the final result
        string ans = "";

        // Pop characters from the stack and append them to the result string
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        // The stack gives the result in reverse order, so reverse the final string
        reverse(ans.begin(), ans.end());

        // Return the final processed string
        return ans;
    }
};

/*
    Validate Stack Sequences (LeetCode 946)(Medium)
    Problem:
    Given two integer sequences pushed and popped, return true if they represent a valid stack operation sequence (push and pop), or false otherwise.

    For example:

    Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1], Output: true.
    Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2], Output: false.

    Detailed Explanation:

    Simulating Stack Operations:
    Push elements from the pushed array to the stack.
    After each push, check if the stack's top matches the next element in the popped array. If it does, pop the element from the stack.
    Edge Cases:
    If pushed and popped are identical, the result is always true.
    If the sequences can't match the order (e.g., if an element appears in popped before it was pushed), the result is false.

    Time Complexity:
    O(n): Each element is pushed and popped at most once.

    Space Complexity:
    O(n): The stack can hold up to n elements in the worst case.

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;  // Stack to simulate the push and pop operations
        int i = 0;  // Index for popped sequence
        
        // Traverse through each element in the pushed array
        for(int v = 0; v < pushed.size(); v++) {
            st.push(pushed[v]);  // Push the current element to the stack
            
            // Check if top of the stack matches the current popped element
            while(!st.empty() && st.top() == popped[i]) {
                st.pop();  // Pop if it matches
                i++;  // Move to the next element in popped array
            }
        }
        
        // If stack is empty, the sequence was valid
        return st.empty();
    }
};

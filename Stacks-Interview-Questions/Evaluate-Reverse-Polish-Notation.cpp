/*

Evaluate Reverse Polish Notation (LeetCode: 150) (Medium)
Problem:
Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).

Valid operators are +, -, *, and /.
Each operand may be an integer or another expression.
Solution Explanation:

Use a stack to store operands.
When an operator is encountered, pop the top two elements from the stack, apply the operator, and push the result back onto the stack.

Time Complexity:

O(n), where n is the number of tokens in the input.

Space Complexity:

O(n), due to the stack used for storing operands.

*/

class Solution {
public:
    int find(int a, int b, string ch) {
        if (ch == "+") {
            return a + b;
        } else if (ch == "-") {
            return a - b;
        } else if (ch == "*") {
            return a * b;
        } else {
            return a / b;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for (int i = 0; i < n; ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();

                int result = find(top2, top1, tokens[i]);
                st.push(result);
            } else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};

/*

Daily Temperatures (LeetCode: 739)(Medium)
Problem:
Given a list of daily temperatures, return a list such that for each day, you tell how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

Solution Explanation:

Use a stack to store indices of temperatures.
As you process each day's temperature, compare it with the temperature at the index on the top of the stack. If the current temperature is warmer, calculate the difference in days.

Time Complexity:

O(n), where n is the number of temperatures. Each element is pushed and popped from the stack at most once.

Space Complexity:

O(n), due to the stack and the result array.


*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

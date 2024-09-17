/*
Remove Stones to Minimize the Total (LeetCode: 1962) Medium
Problem:
Given a set of stone piles, each pile has a certain weight. You can perform a specific operation k times: for each operation, remove half of the largest pile's weight. Return the sum of the remaining pile weights after performing all k operations.

Solution Explanation:

Use a max-heap to repeatedly remove the largest pile, reduce its weight, and push the reduced pile back into the heap.
After k operations, sum the weights of the remaining piles.

Time Complexity:

O(k log n) due to heap operations, where n is the number of piles and k is the number of operations.

Space Complexity:

O(n), space used by the heap.

*/


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq; // Max-heap

        for (int pile : piles) {
            pq.push(pile);
        }

        while (k--) {
            int top = pq.top();
            pq.pop();
            int reduced = top - top / 2;
            pq.push(reduced);
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};

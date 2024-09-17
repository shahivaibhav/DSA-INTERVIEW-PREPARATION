/*
Last Stone Weight (LeetCode: 1046) Easy

Problem:
You are given a collection of stones, and each stone has a weight. Each time, you select the two heaviest stones and smash them together. If the two stones have the same weight, both are destroyed. If not, the stone with the larger weight is reduced by the weight of the smaller stone. Repeat this until only one or zero stones are left.

Solution Explanation:

Use a max-heap (priority queue) to store the stone weights.
Repeatedly pop the two heaviest stones, smash them, and push the remaining weight (if any) back into the heap.
The result is either the weight of the last remaining stone or 0 if all stones are destroyed.

Time Complexity:

O(n log n) due to heap operations, where n is the number of stones.

Space Complexity:

O(n), space used by the heap.


*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();

            if (top1 != top2) {
                pq.push(top1 - top2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

/*
    Top K Frequent Elements (LeetCode 347)(Medium)
    Problem:
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Solution Explanation:
    We use a hash map to count the frequency of each element, and then we use a max-heap (priority queue) to retrieve the top k most frequent elements.

    Detailed Explanation:

    Count Frequencies: We first iterate over the nums array and store the frequency of each number in an unordered_map, where the key is the number and the value is its frequency.
    Priority Queue: We then push each element from the map into a max-heap (priority queue), where the priority is based on the frequency of the element. The priority queue is ordered by frequency, so the most frequent elements come to the top.
    Extract Top K: Finally, we pop the top k elements from the heap and store them in the answer vector.
    Result: The result vector contains the top k most frequent elements from the array.

    Time Complexity:
    O(n log k): The frequency count takes O(n), and inserting all elements into the heap takes O(log k) for each element, which results in O(n log k).

    Space Complexity:
    O(n): The space required for the hash map and the priority queue is proportional to the number of unique elements in the array.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Max-heap to store the frequency and corresponding element
        priority_queue<pair<int, int>> pq;
        // Hash map to store the frequency of each element
        unordered_map<int, int> mp;
        // Vector to store the answer
        vector<int> ans;

        // Count the frequency of each element in the array
        for(auto &num : nums) {
            mp[num]++;
        }

        // Insert each element and its frequency into the priority queue (max-heap)
        for(auto &num : mp) {
            pq.push({num.second, num.first});  // max-heap stores pairs (frequency, element)
        }

        // Extract the top 'k' elements from the max-heap
        while(k--) {
            ans.push_back(pq.top().second);  // Get the element from the pair
            pq.pop();  // Remove the top element from the heap
        }

        return ans;  // Return the top k frequent elements
    }
};

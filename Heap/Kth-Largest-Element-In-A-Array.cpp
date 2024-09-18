/*

    Find Kth Largest Element in an Array (LeetCode 215)(Medium)

    Problem:
    Given an integer array nums and an integer k, return the kth largest element in the array.

    Solution Explanation:
    We can solve this problem by using a max-heap (priority queue). We insert all elements into the max-heap, then pop the top k-1 elements, and the top of the heap will be the kth largest element.

    Detailed Explanation:

    Max-Heap Insertion: We push all elements from the array into a max-heap. The heap is automatically ordered, with the largest element at the top.
    Pop K-1 Elements: We pop the top k-1 elements from the heap to remove the largest elements, so that the kth largest element is now on top.
    Return Kth Largest: Finally, the top of the heap is the kth largest element, which we return.
    Time Complexity:
    O(n log n): Building the heap requires O(n log n) since we insert each element into the heap, and each insertion operation takes O(log n) time.

    Space Complexity:
    O(n): We need space to store all elements in the heap, so the space complexity is O(n).
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max-heap to store all elements
        priority_queue<int> pq;

        // Insert all elements of the array into the max-heap
        for(auto &num : nums) {
            pq.push(num);
        }

        // Remove the first (k-1) elements from the heap
        k--;  // We need to pop (k-1) elements to get the kth largest element
        while(k--) {
            pq.pop();
        }

        // The top of the heap is now the kth largest element
        return (pq.empty()) ? -1 : pq.top();
    }
};

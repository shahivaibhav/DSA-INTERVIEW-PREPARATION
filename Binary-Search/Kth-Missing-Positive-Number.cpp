/*
Leetcode 1539:- Find Kth Missing Positive Number(Easy)

Problem:
You are given a sorted array of positive integers, and you need to find the k-th missing positive number.

Approach:
The array contains numbers that may skip certain positive integers. For example, if the array is [2, 3, 4, 7, 11], the missing numbers are [1, 5, 6, 8, 9, 10, 12, ...]. You need to efficiently find the k-th missing number.

Using binary search, you can figure out where the k-th missing number falls by tracking how many numbers are missing up to any given point in the array.

Key Insight:

For each index mid, the number of missing elements is arr[mid] - (mid + 1). Using binary search, you adjust start and end based on the count of missing numbers, which leads to an efficient solution.

Time Complexity: O(log n)
Space Complexity: O(1)

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;

        // Binary search to determine the correct position
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missingNumbers = arr[mid] - (mid + 1);  // Number of missing numbers up to index mid

            if (missingNumbers < k) {
                start = mid + 1;  // Look for more missing numbers
            } else {
                end = mid - 1;  // Narrow the search space
            }
        }

        // Return the k-th missing number
        return start + k;
    }
};

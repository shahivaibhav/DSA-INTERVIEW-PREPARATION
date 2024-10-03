/*

Leetcode 2439:- Minimize Maximum of Array(Medium)

Problem Overview:
The task is to minimize the maximum value of an array by redistributing the elements. The goal is to find the smallest possible maximum value for the array by distributing excess values to adjacent elements.

Input:

nums – an array of integers.
Solution Approach:
Binary Search over Possible Maximum Values:

The problem is solved using binary search on the range of possible maximum values, starting from nums[0] to the maximum value in the array.
Each mid value is considered as a potential maximum, and the function isValid checks if it is possible to reduce all elements in the array to be less than or equal to mid by redistributing values.
Check Validity of Mid Value:

The isValid function simulates reducing the array such that all elements are less than or equal to mid.
It creates a temporary array temp and performs redistribution by ensuring that each element temp[i] is adjusted to be less than or equal to mid.
If any element cannot be reduced to mid, the value is considered invalid, and binary search moves to a higher range.
Adjust Binary Search:

If a mid value is valid, update the answer and search for a smaller maximum value (end = mid - 1).
If not, search in the higher range (start = mid + 1).

Time Complexity Analysis:

Binary Search over Potential Maximum Values:
The binary search iterates over a range of possible values for the maximum value.
This range is bounded by the initial maximum value in the array, i.e., O(log(max(nums))).
isValid Check:
For each mid value, the isValid function checks if we can make all elements less than or equal to mid.

This takes O(n) time, where n is the length of the array.

Therefore, the overall time complexity is O(n * log(max(nums))).

Space Complexity:

The isValid function uses an additional array temp to perform operations, making the space complexity O(n).

*/

class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int n) {
        vector<long long> temp(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] > mid) {
                return false;  // If the current element is greater than mid, the mid value is invalid
            }
            // Calculate the excess that can be passed to the next element
            long long diff = mid - temp[i];
            temp[i + 1] -= diff;  // Distribute the excess to the next element
        }
        return temp[n - 1] <= mid;  // Ensure that the last element is within the mid value
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int start = nums[0];
        int maxi = *max_element(nums.begin(), nums.end());
        int end = maxi;

        // Binary search to find the minimum possible maximum value
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValid(nums, mid, n)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;  // Start now points to the minimized maximum value
    }
};

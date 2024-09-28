/*

Leetcode 153 :- Find Minimum in Rotated Sorted Array(Medium)

Problem Summary:
This function finds the minimum element in a rotated sorted array. A rotated sorted array is created by taking a sorted array and rotating it by some pivot unknown to you beforehand.

Detailed Explanation:
Binary Search in Rotated Array: The goal is to use binary search to efficiently find the smallest element in a rotated array. If the array was not rotated, the smallest element would be at nums[0]. But since it’s rotated, the smallest element will be the point where the rotation happens.

Key Observation:

If nums[mid] > nums[end], this means the smallest element is in the right half.
Otherwise, the smallest element is in the left half or is the mid itself.

Key Insights:

Time Complexity: O(log n) because we perform binary search.
Space Complexity: O(1) as only a few variables are used.

Edge Cases:
If the array is not rotated, the smallest element is the first element.
If the array has only one element, the function should return that element.


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0; 
        int end   = nums.size() - 1;

        // Binary search to find the pivot (smallest element)
        while(start < end){
            int mid = start + (end - start)/2;

            // If middle element is greater than the rightmost, the minimum is on the right
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{  // If middle element is smaller, the minimum is on the left
                end = mid;
            }
        }

        // At the end, start will be the minimum element
        return nums[end];
    }
};

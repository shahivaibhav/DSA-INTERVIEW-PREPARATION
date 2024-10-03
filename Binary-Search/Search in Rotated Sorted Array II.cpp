/*
Leetcode 81:- Search in Rotated Sorted Array II(Medium)

Detailed Explanation:

findPivot function:
This function finds the pivot element, which is the smallest element in a rotated sorted array.
It uses binary search to locate the pivot by comparing the middle element (mid) with the end element (end).
If nums[mid] < nums[end], the pivot is in the left half. If nums[mid] >= nums[end], the pivot is in the right half.
The loop continues until start and end converge at the pivot index.

binarySearch function:
This function performs a standard binary search on a sorted subarray.
It repeatedly checks the middle element (nums[mid]) against the target and narrows down the search space accordingly.

search function:
The main function uses findPivot to split the array into two parts: left (before pivot) and right (after pivot).
It then performs a binary search on both parts to see if the target is present in either part.

Time Complexity :- 

findPivot Function:
The findPivot function uses a modified binary search to locate the smallest element (pivot) in the rotated array.
In the worst case, due to duplicate elements, the function might degrade to O(n) instead of O(log n).

binarySearch Function:
Performs a standard binary search, which takes O(log n) time.
search Function:

The function calls findPivot once and then performs binarySearch on two separate parts of the array.

Hence, the overall time complexity is O(n) in the worst case.

Space Complexity:-
All operations are performed in-place, and no extra space is used except for a few variables (like start, end, mid), which take constant space.
Thus, the space complexity is O(1).

*/

class Solution {
public:
    // Function to find the index of the pivot (minimum element) in a rotated sorted array
    int findPivot(vector<int>& nums, int start, int end) {

        // Using binary search to find the pivot element
        while (start < end) {

            // Skip duplicate elements at the start to avoid incorrect mid calculation
            while (start < end && nums[start] == nums[start + 1]) {
                start++;
            }

            // Skip duplicate elements at the end
            while (end > start && nums[end] == nums[end - 1]) {
                end--;
            }

            // Calculate mid index
            int mid = start + (end - start) / 2;

            // If mid element is less than the end element, pivot is in the left half
            if (nums[mid] < nums[end]) {
                end = mid;
            } else { // Otherwise, pivot is in the right half
                start = mid + 1;
            }
        }

        return end; // Return the index of the pivot (minimum element)
    }

    // Function to perform binary search in a sorted array
    bool binarySearch(int start, int end, int target, vector<int>& nums) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                start = mid + 1; // Search in the right half
            } else {
                end = mid - 1; // Search in the left half
            }
        }
        return false; // Target not found
    }

    // Main function to search the target in the rotated sorted array
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Find the pivot (smallest element) index
        int pivot = findPivot(nums, 0, n - 1);

        // Step 2: Perform binary search in the left and right parts of the array
        if (binarySearch(0, pivot - 1, target, nums)) {
            return true; // Found target in the left part
        }

        // Step 3: Perform binary search in the right part (pivot to end)
        return binarySearch(pivot, n - 1, target, nums);
    }
};

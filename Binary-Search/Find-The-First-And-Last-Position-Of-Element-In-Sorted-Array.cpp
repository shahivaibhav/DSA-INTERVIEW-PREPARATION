/*

Leetcode 34 :- Find First and Last Position of Element in Sorted Array(Medium)

Problem Summary:
The function aims to find the first and last occurrence of a target element in a sorted array. If the target is not present, it returns {-1, -1}. The task is accomplished using binary search, an efficient way to search through a sorted list in O(log n) time.

Detailed Explanation:
Binary Search: Binary search is used twice in this solution to efficiently find the leftmost and rightmost indices of the target element in the array.

Leftmost Index (findLeftIndex):

We look for the leftmost occurrence of the target element.
If nums[mid] == target, we store the index in left_i and continue to move end to mid-1 to search the left half of the array.
This ensures that the leftmost target index is found.
Rightmost Index (findRightIndex):

We do a similar binary search to find the rightmost occurrence.
If nums[mid] == target, we store the index in right_i and continue to move start to mid+1 to search the right half of the array.

Key Insights:
Time Complexity: 
Since we are performing binary search twice, the time complexity is O(log n).

Space Complexity: 
The space complexity is O(1) since no extra space is used except for variables.

Edge Cases:
If the target is not in the array, both findLeftIndex and findRightIndex return -1, giving the output {-1, -1}.
If the array contains a single element and it matches the target, both indices will be the same.

*/


class Solution {
public:

    // Function to find the leftmost (first) index of the target using binary search
    int findLeftIndex(vector<int>& nums, int target){
        int start   = 0;
        int end     = nums.size() - 1;
        int left_i  = -1;  // Initialize left index as -1 (not found)

        while(start <= end){
            int mid = start + (end - start)/2;  // Find the mid-point

            if(nums[mid] > target){  // Move left if mid element is larger than target
                end = mid - 1;
            }
            else if(nums[mid] < target){  // Move right if mid element is smaller than target
                start = mid + 1;
            }
            else{  // Found target, but continue to search towards the left
                left_i = mid;
                end    = mid-1;
            }
        }
        return left_i;  // Return the leftmost index
    }

    // Function to find the rightmost (last) index of the target using binary search
    int findRightIndex(vector<int>& nums, int target){
        int start   = 0;
        int end     = nums.size() - 1;
        int right_i = -1;  // Initialize right index as -1 (not found)

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] > target){  // Move left if mid element is larger than target
                end = mid - 1;
            }
            else if(nums[mid] < target){  // Move right if mid element is smaller than target
                start = mid + 1;
            }
            else{  // Found target, but continue to search towards the right
                right_i = mid;
                start   = mid + 1;
            }
        }
        return right_i;  // Return the rightmost index
    }

    // Main function to return the range of the target
    vector<int> searchRange(vector<int>& nums, int target) {
        int left_i  = findLeftIndex(nums, target);   // Get the leftmost index
        int right_i = findRightIndex(nums, target);  // Get the rightmost index

        return {left_i, right_i};  // Return the range as a pair
    }
};

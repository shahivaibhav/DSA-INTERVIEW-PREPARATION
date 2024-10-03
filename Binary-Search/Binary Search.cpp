/*

Leetcode 704:- Binary Search(Easy)

Detailed Explanation:

Initialization:
Start and end pointers are set to the beginning and end of the array, respectively.
Binary Search Loop:
A while loop runs until start is less than or equal to end.
The middle element (mid) is calculated to avoid overflow issues.
Condition Check:
If the target is found at mid, return the index.
If the target is greater than mid, update start to mid + 1.
If the target is less than mid, update end to mid - 1.
Return Statement:
If the target is not found after exhausting the search space, return -1.

Time Complexity Analysis:

The binary search function runs in O(log n) time, where n is the number of elements in the array.
This is because the array is repeatedly divided into half until the target is found or the search space is exhausted.

Space Complexity:

The space complexity is O(1) since no additional memory is allocated, and only a few variables (start, end, mid) are used.

*/

class Solution {
public:
    // Function to perform binary search in a sorted array
    int search(vector<int>& nums, int target) {
        
        int start = 0;               // Starting index of the array
        int end = nums.size() - 1;    // Ending index of the array

        // Binary search loop: continue until start index is less than or equal to end index
        while (start <= end) {
            int mid = start + (end - start) / 2;  // Calculate middle index to avoid overflow

            if (nums[mid] == target) {  // If target is found at mid index
                return mid;
            } else if (nums[mid] < target) {  // If target is greater than mid value, search right half
                start = mid + 1;
            } else {  // If target is less than mid value, search left half
                end = mid - 1;
            }
        }
        return -1;  // Return -1 if the target is not found
    }
};

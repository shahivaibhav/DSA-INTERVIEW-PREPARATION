/*

Leetcode 4 :-  Median of Two Sorted Arrays(Hard)
 
Problem Understanding:
You are given two sorted arrays nums1 and nums2, and the task is to find the median of the combined sorted array.

Key Observations:
Binary Search on Smaller Array: The solution uses binary search on the smaller array (nums1 or nums2) to partition both arrays at a point where the median can be easily calculated.
Partitioning: The total number of elements is divided into two halves. The partitioning ensures that the left half contains smaller elements than the right half.

Approach:
Binary Search Setup:

Perform binary search on the smaller array (nums1).
Use two pointers l and r to perform binary search.
Partitioning:

px is the partition index for nums1.
py is calculated using (m + n + 1) / 2 - px, which ensures the combined left half contains (m + n + 1) / 2 elements.
The left half contains the elements to the left of px in nums1 and the elements to the left of py in nums2.
Checking Valid Partition:

You compare the largest element on the left half (x1 from nums1 and x2 from nums2) with the smallest element on the right half (x3 from nums1 and x4 from nums2).
If x1 <= x4 and x2 <= x3, the partition is valid, and you can calculate the median based on the total number of elements (odd or even).
Binary Search Adjustments:

If x1 > x4, it means the partition is too far to the right in nums1, so you reduce r.
If x2 > x3, the partition is too far to the left, so you increase l.

Code Walkthrough:
Base Case: If nums2.size() < nums1.size(), you swap them to ensure binary search is performed on the smaller array.
Variables:
l and r are the binary search bounds on nums1.
px is the partition index in nums1, and py is the partition index in nums2.
x1, x2, x3, and x4 represent boundary values around the partitions.

Binary Search:
The while loop continues until a valid partition is found.
If a valid partition is found, the median is calculated and returned.

Time and Space Complexity:

Time Complexity: O(log(min(n, m))) because binary search is applied to the smaller array.
Space Complexity: O(1) since only a few extra variables are used.

Example Walkthrough:
Suppose:

nums1 = [1, 3]
nums2 = [2]
The binary search will partition both arrays such that the median is found, which in this case will be 2.

*/

class Solution {
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Ensure that binary search is performed on the smaller array
        // If nums1 is larger than nums2, swap them.
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);  // Call function again with swapped arrays
        }

        // `n` is the size of nums1, `m` is the size of nums2
        int n = nums1.size();
        int m = nums2.size();

        // Set the binary search bounds for nums1
        int l = 0;  // Left bound
        int r = n;  // Right bound

        // Start binary search to partition the two arrays
        while(l <= r){

            // Partition index for nums1
            int px = l + (r - l)/2;

            // Partition index for nums2
            // (m + n + 1) / 2 ensures that the left side of the partition has the same number of elements as the right side
            int py = (m + n + 1)/2 - px;

            // Left side values
            // x1 is the largest value on the left side of nums1
            // If px == 0, it means there are no elements on the left side, so we assign it to INT_MIN
            int x1 = (px == 0) ? INT_MIN : nums1[px-1]; 

            // x2 is the largest value on the left side of nums2
            // If py == 0, it means there are no elements on the left side, so we assign it to INT_MIN
            int x2 = (py == 0) ? INT_MIN : nums2[py-1]; 

            // Right side values
            // x3 is the smallest value on the right side of nums1
            // If px == n, it means all elements of nums1 are on the left, so we assign it to INT_MAX
            int x3 = (px == n) ? INT_MAX : nums1[px]; 

            // x4 is the smallest value on the right side of nums2
            // If py == m, it means all elements of nums2 are on the left, so we assign it to INT_MAX
            int x4 = (py == m) ? INT_MAX : nums2[py]; 

            // Check if the partition is correct
            // The largest value on the left side must be smaller than or equal to the smallest value on the right side
            if(x1 <= x4 && x2 <= x3){
                
                // If the total number of elements is odd, the median is the maximum value on the left side
                int maxi = max(x1, x2); // Maximum of x1 and x2
                int mini = min(x3, x4); // Minimum of x3 and x4

                if( (m + n) % 2 == 1){
                    return maxi;  // If total elements are odd, return the maximum of left side
                }

                // If the total number of elements is even, the median is the average of the maximum of the left side and the minimum of the right side
                return (maxi + mini) / 2.0;

            }

            // If the left side of nums1 has a larger element than the right side of nums2, move the partition to the left
            if(x1 > x4){
                r = px - 1;
            }
            // Otherwise, move the partition to the right
            else{
                l = px + 1;
            }

        }

        // If no median is found, return -1 (this should not happen with valid input)
        return -1;

    }
};

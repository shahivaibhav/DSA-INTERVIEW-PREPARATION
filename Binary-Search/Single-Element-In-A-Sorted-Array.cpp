/*

Leetcode 540 :- Single Element in a Sorted Array(Medium)

Problem Summary:
In this problem, each element in a sorted array appears exactly twice, except for one element which appears only once. The task is to find that single non-duplicate element in O(log n) time using binary search.

Detailed Explanation:
Binary Search with Even/Odd Index Check:
We can split the array into pairs of elements. If the pair starts at an even index, the non-duplicate element lies in the right half. Otherwise, it’s in the left half.
Use binary search to find the point where this property breaks (i.e., where the non-duplicate element is).

Key Insights:

Time Complexity: O(log n) because binary search is applied.
Space Complexity: O(1) because no extra space is used.

Edge Cases:
If the array has only one element, that is the non-duplicate element.
Works with both odd and even-length arrays.

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left  = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left) / 2;
            bool isEven;

            if((right - mid) % 2 == 0){
                isEven = true;
            }
            else{
                isEven = false;
            }

            if(nums[mid] != nums[mid + 1]){  // Check if mid element is part of the pair
                if(isEven){
                    right = mid;  // Move towards left if the first half is even
                }
                else{
                    left = mid + 1;  // Move right if the first half is odd
                }
            }
            else{
                if(isEven){
                    left = mid + 2;  // Move right if the second half is even
                }
                else{
                    right = mid - 1;  // Move left if the second half is odd
                }
            }
        }

        return nums[right];  // At the end, left == right, return single element
    }
};

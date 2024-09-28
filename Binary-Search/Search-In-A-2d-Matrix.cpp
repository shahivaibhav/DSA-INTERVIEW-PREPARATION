/*

Leetcode 74:- Search a 2D Matrix(Medium)

Problem Summary:
Given an n x m matrix, where each row is sorted and the first element of each row is greater than the last element of the previous row, the task is to determine if a given target exists in the matrix.

Detailed Explanation:
Flattening the Matrix: Since each row and column are sorted, we can treat the matrix as a 1D sorted array. The row index and column index can be derived using simple formulas:
matrix[mid / m][mid % m] gives the element at the mid position in a 2D matrix treated as 1D.

Key Insights:

Time Complexity: O(log (n * m)) since we are performing binary search on the flattened 1D array.
Space Complexity: O(1).

Edge Cases:
If the matrix has only one row or one column, it should still work efficiently.
If the target is smaller or larger than any element in the matrix, it returns false.

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n     = matrix.size();    // Number of rows
        int m     = matrix[0].size();  // Number of columns
        int start = 0;
        int end   = n * m - 1;        // Treat the 2D matrix as a 1D array

        // Binary search over the "1D" array
        while(start <= end){
            int mid     = start + (end - start) / 2;
            int element = matrix[mid / m][mid % m];  // Calculate the actual 2D index

            if(element == target){
                return true;
            }
            else if(element < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;  // Target not found
    }
};

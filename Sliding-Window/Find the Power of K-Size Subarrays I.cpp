
/*

Leetcode 3254: Find the Power of K-Size Subarrays I(Medium)

Intuition:-

After reading the problem statement and first example, we undestand it is a sliding window problem.

--Example Dry run:-

Note:- We are updating maximum element also while moving in current window to next window.

Approach:-

1. We will traverse in input array.
2. We will have 2 pointers "i" and "j" for using sliding window.
3. We will have "count" variable to count number of consecutive increasing subarray.
4. We will also store maximum element in "maxElement" variable.
5. If our window size reaches to "k", we will see if our count is equal to k or not.
6. If count is also equal to "k", then we will push maxElement in  ans else we will push "-1".
7. We will also keep checking if our maxElement is keep updating or not, there may be cases where our maxElement is of previous window.

Time complexity  :- O(n)
Space complexity :- O(n)

*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();        

        int maxElement = -1;
        int count      = 0;

        vector<int> ans;

        while(j < n){

            //Updating the maxElement
            if(maxElement < nums[j]){
                maxElement = nums[j];
            }

            //Checking if consecutive numbers
            if(j == 0 || (nums[j] - nums[j-1] == 1)){
                count++;
            }
            else{
                count = 1;
            }

            //If we reach next window
            if(j-i+1 > k){
                bool flag = false;
                if(maxElement = nums[i]){//If our maxElemnt was of previous window
                    flag = true;
                }
                i++;
                if(flag){
                    maxElement = nums[j];
                }
            }

            //We have checked all elements of our window
            if(j - i + 1 == k){
                if(count == k){
                    ans.push_back(maxElement);
                    count--;
                }
                else{
                    ans.push_back(-1);
                }
            }

            j++;

        }

        return ans;
    }
};
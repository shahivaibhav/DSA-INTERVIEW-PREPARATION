/*
Leetcode 2461:- Maximum Sum of Distinct Subarrays With Length K(Medium)
Intution:-

-- The problem statement is written such that we get the hint of sliding window by reading first required condition.
-- We want to calculate the maximum sum of "k" size window of array.
-- The only catch is that we need to find the sum of distinct elements.
-- For that purpose , we can use "set" or "map".

Approach:-
1.) We would be using typical sliding window for looking in the window.
2.) We will store elements in set while traversing.
3.) We will check if element is already present or not.
4.) If element is already present in the set => we will shrink our window and erase the element from set using "i" pointer[starting index of window].
5.) We will also subtract the element from our answer sum.
6.) Else we will insert the element in the set and add it to the answer sum.
7.) If length of window reaches required size => "k", we will update our answer and shrink the window.

Time complexity :- O(n)
Space complexity:- O(n)

*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_set<int> st;

        int i = 0;
        int j = 0;
        int n = nums.size();

        long long maxAns = 0;
        long long sum    = 0;

        while(j < n){

            while(st.find(nums[j]) != st.end()){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }   

            st.insert(nums[j]);
            sum += nums[j];

            if(j - i + 1 == k){

                maxAns = max(maxAns, sum);
                
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return maxAns;
    }
};
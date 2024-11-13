/*

Leetcode 2563 :- Count the Number of Fair Pairs(Medium)

Intution:-

--This problem is a little bit tricky. However,the problem statement was easy to understand.
--We only want to count the number of pairs whose sum is greater equal to a certain value["lower"] and less than equal to certain value["upper"].

Ex- lower = 2, upper = 5, arr = [1, 2, 3, 4, 5] so pairs [1,2] and [1, 3] are valid.

So what we did here was, we are finding upper values for each arr[i] such that it matches the required criteria by traversing in it.
It will be easy to find such elements if we sort it.
Ex:- If arr = [1, 2, 3, 4, 5] and lower = 2, upper = 5
When our arr[i] = 2 and we reach 4 when seraching for its other element we will not search further as 2+4 = 6 which is greater than upper and further elements will be greater then 4 itself.

Binary Search + Sliding Window Approach:-

1. We will traverse in the input array and try to find valid pair for each element.
2. We will store lowest Index[lowestIdx] where element is greater or equal to "lower". 
3. We will store highest Index[highestIdx] where element is smaller or equal to "upper".
//"Note that we will be doing 2 and 3 step for each element."
4. We will calculate the window size[as lowestIdx denotes starting point from where valid pair starts and highestIdx denotes ending point for valid pairs].
5. Add it in the ans.

Time Complexity:-
1.Sorting
O(nlogn)
2.Traversal and finding valid pairs
O(n)[Traversing each element]
O(2*logn)[BinarySeach]
Overall complexity in this step :- O(n*2logn)

Overall Time Complexity:- O(nlogn)

Space Complexity:- O(1)


*/


class Solution {
public:

    typedef long long ll;

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());

        int n    = nums.size();

        ll count  = 0;

        for(int i = 0; i < n; i++){

            int lowestNumRequired  = lower - nums[i];
            int highestNumRequired = upper - nums[i]; 

            int lowestIdx  = n;
            int highestIdx = -1;

            //Binary Search for finding lowestIdx

            int start = i+1;
            int end   = n-1;

            while(start <= end){
                int mid = start + (end - start)/2;

                if(nums[mid] < lowestNumRequired){
                    start = mid + 1;
                }
                else{
                    lowestIdx = min(lowestIdx, mid);
                    end = mid - 1;
                }
            }

            if(lowestIdx == n){
                continue;
            }

            //Binary Search for finding highestIdx

            start = i+1;
            end   = n-1;

            while(start <= end){
                int mid = start + (end - start)/2;

                if(nums[mid] > highestNumRequired){
                    end = mid - 1;
                }
                else{
                    highestIdx = max(highestIdx, mid);
                    start = mid + 1;
                }
            }

            if(highestIdx == -1){
                continue;
            }

            int currWindowSize = highestIdx - lowestIdx + 1;
            count = (ll)count + (ll)currWindowSize;

        }

        return count;
        
    }
};
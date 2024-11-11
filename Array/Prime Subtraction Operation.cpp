/*

Leetcode 2601:- Prime Subtraction Operation(Medium)

Intuition:-

The problem question is straight forward:-
1. If our current elemenet is smaller then next element then we need not to do anything.
2. But if our current element is not smaller then next element, then we need to subtract current element by prime numbers smaller to it such that is becomes smaller to next element.
    If we are unable to do this, we will return false.

So by understanding the problem, we will be needing a vector where prime numbers will be stored.
We can use greedy approach "Sieve of Eratosthenes" for this purpose.

In constraints we are provided that maximum value in nums will be 1000, so we create a vector of size 1000 for storing prime numbers.

Approach:-

As we want to check current element is smaller to next element or not, so to make our code easy, we will traverse from end.
If our element is smaller then we will continue.
Else we will subtract prime number from element and check that if it can be made smaller.
If not then we will return false.

Time complexity :- O(n)
Space complexity:- O(n)

*/


class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primeNumber(1001, 1);

        primeNumber[0] = 0;
        primeNumber[1] = 0;

        for(int i = 2; i*i <= 1000; i++){
            if(primeNumber[i] == 1){
                for(int j = i*i; j <= 1000; j += i){
                    primeNumber[j] = 0;
                }
            }
        }

        int n = nums.size();

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                continue;
            }

            for(int p = 2; p < nums[i]; p++){
                if(!primeNumber[p]){
                    continue;
                }

                if(nums[i] - p < nums[i+1]){
                    nums[i] = nums[i] - p;
                    break;
                }
            }

            if(nums[i] >= nums[i+1]){
                return false;
            } 
        }

        return true;
    }
};
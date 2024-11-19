/*

Leetcode 1388:- Pizza With 3n Slices(Hard)

#Intuition
The problem is similar to House Robber 2. Here, we need to find the maximum amount of pizza we can it.

--If we have eaten a slice, we can not eat its adjacent slice
Eg:-  
        
    1 -> 2 ->  3
                |
    6 <- 5  <- 4

So, we eat slice number 1 => we can not eat slice number 2 and 6 as it is adjacent to slice number 1.

**So, we have option for eating pizza from 1 to 5 or 2 to 6 as we can not eat 1 and 6 together.**

-- We have options in any case as, we can eat a particular slice to maximise the ans, or we can skip it.
-- The cases where we have options, we use **recursion**.
-- Here many repeated sub-problems occur during recursion, so we will be solving this problem using dynamic programming concept.
 

# Approach

If the input array size is "k", then a person can eat k/3 slices of pizza, **remainingSlice** = k/3

We will find answers from 0 to k-2 index and 1 to k-1 index separately as we have discussed the logic before.

So **startPoint** can be 0 or 1.
Correspondigly **endPoint** will be k-2 or k-1.

## Base Case 

-- If our remainingSlices becomes 0 => we need not to eat any more slices.
So we will return 0.

-- If we get out of the array[index gets out of array], we will return 0 as we can not eat any slice.

    if(remainingSlices == 0 || startPoint > endPoint){
        return 0;
    }

## Recursive Relation

-- Here we have 2 options, either we can eat a slice or we can skip it so that in future we get a better answer.

**If we eat a Slice -**
We will not eat next slice, means we have to go to next to next slice.

          startPoint = startPoint+2
Also as we have eaten a slice, so remaining slice will decrease.

        remainingSlices = remainingSlices - 1

**If we skip current Slice**-
If we skip current slice, then we can eat the next slice.
          startPoint = startPoint+1
Also as we have not eaten a slice, so remaining slice will be same.

        remainingSlices = remainingSlices

So our overall Recursive solution of function **getMaxPizza** will be

    int eat_Pizza  = slices[startPoint] +  getMaxPizza(startPoint+2, endPoint, slices, remainingSlices - 1);
    int skip_Pizza = 0 + getMaxPizza(startPoint+1, endPoint, slices, remainingSlices);

**Returning answer**

We will return maximum answer obtained from eating from 0 to k-2 and 1 to k-1.

# Complexity
- Time complexity:
O(2^k) [Recurive solution]
O(n^k) [Memoization]
O(n^k )[Tabulation]

- Space complexity:
O(k) [Recurive solution]
O(n^k) [Memoization]
O(n^k) [Tabulation]
*/

// Code


//Recursion

int getMaxPizza(int startPoint, int endPoint, vector<int>& slices, int remainingSlices){

        if(remainingSlices == 0 || startPoint > endPoint){
            return 0;
        }

        int eat_Pizza  = slices[startPoint] +  getMaxPizza(startPoint+2, endPoint, slices, remainingSlices - 1);
        int skip_Pizza = 0 + getMaxPizza(startPoint+1, endPoint, slices, remainingSlices);

        return max(eat_Pizza, skip_Pizza);

    }

    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();
        int n = k/3;

        int max_start = getMaxPizza(0, k - 2, slices, n);
        int max_end   = getMaxPizza(1, k - 1, slices, n);

        return max(max_start, max_end);

    }
-------------------////////////////////---------------------------
// Memoization

    int getMaxPizza(int startPoint, int endPoint, vector<int>& slices, int remainingSlices, vector<vector<int>> &dp){

        if(remainingSlices == 0 || startPoint > endPoint){
            return 0;
        }

        if(dp[startPoint][remainingSlices] != -1){
            return dp[startPoint][remainingSlices];
        }

        int eat_Pizza  = slices[startPoint] +  getMaxPizza(startPoint+2, endPoint, slices, remainingSlices - 1, dp);
        int skip_Pizza = 0 + getMaxPizza(startPoint+1, endPoint, slices, remainingSlices, dp);

        dp[startPoint][remainingSlices] = max(eat_Pizza, skip_Pizza);
        
        return dp[startPoint][remainingSlices];

    }

    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();
        int n = k/3;

        vector<vector<int>> dp1(k, vector<int>(n+1, -1));
        vector<vector<int>> dp2(k, vector<int>(n+1, -1));

        int max_start = getMaxPizza(0, k - 2, slices, n, dp1);
        int max_end   = getMaxPizza(1, k - 1, slices, n, dp2);


        return max(max_start, max_end);

    }

    -----------------------////////////////////-------------------------
//Tabulation 

class Solution {
public:
    int getMaxPizza(vector<int>& slices, int start, int end, int n) {
        int len = end - start + 1;
        vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0));

        for (int i = len - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                int take = slices[start + i] + (i + 2 < len ? dp[i + 2][j - 1] : 0);
                int skip = dp[i + 1][j];
                dp[i][j] = max(take, skip);
            }
        }

        return dp[0][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k / 3;

        // Case 1: Exclude the last slice
        int case1 = getMaxPizza(slices, 0, k - 2, n);

        // Case 2: Exclude the first slice
        int case2 = getMaxPizza(slices, 1, k - 1, n);

        return max(case1, case2);
    }
};
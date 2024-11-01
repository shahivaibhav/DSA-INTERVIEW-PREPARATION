/*

Leetcode 2463:- Minimum Total Distance Traveled(Hard)

Intuition:-

The problem demands us to find the minimum total distance travelled to repair from factories with certain conditions.
Key Observations:-

For minimum distance to travel by robot to reach certain factory:- We can do this efficiently if robot is closer to factory.
This means if our robot will be closer to factory then we will have to travel less distance.
For this purpose only we will sort both factory and robot vectors.

Approach:-

This question is a similar question to a standard problem of 0/1 Knapsack.
We will use recursive + Memoization approach.

We will always have two choices whether to repair from current factory or not.
So basically we can include the current distance from robot to factory in answer or we can skip.

Based on these conditions we will write our recurive code.

Decreasing code complexity:-
As our factory vector is a 2d matrix where factory[i][0] indicates factory position and factory[i][1] indicated its limit("i" is index no. of specific factory)
So we can make a separate position vector where we will fill factories according to their limits.

n -> size of robot vector, m -> size of position vector, k -> size of factory vector

Time Complexity :- O(n*m) + O(nlogn) + O(klogk)
Space Complexity:- O(n*m)

*/

class Solution {
public:

    typedef long long ll;

    vector<vector<ll>> dp;

    ll solve(vector<int> &r, vector<int> &p, int i, int j){
        
        // i -> index for robot
        // j -> index for pos

        if(i >= r.size()){
            return 0;
        }

        if(j >= p.size()){
            return 1e12;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        ll take    = abs(r[i] - p[j]) + solve(r, p, i+1, j+1);
        ll notTake = solve(r, p, i, j+1);

        return dp[i][j] = min<ll>(take, notTake);

    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        

        //Step 1:- Sort the robot and factory arrays so that we can search optimally.
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        //Step 2:- Create and fill positions vector so that we can track the factory and it's limit.
        vector<int> positions;
        int n = factory.size();

        for(int i = 0; i < n; i++){
            
            int pos    = factory[i][0];
            int limit  = factory[i][1];

            while(limit--){
                positions.push_back(pos);
            }
        }

        //Step 3:- Recurive solution + memoization

        int m = robot.size();
        n = positions.size();

        dp = vector<vector<ll>>(m, vector<ll>(n, -1));

        return solve(robot, positions, 0, 0);
    }
};
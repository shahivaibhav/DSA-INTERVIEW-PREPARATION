
/*

Leetcode 2924:- Find Champion 2(Medium)

# Intuition

The question is too simple. We only want to check whether **any node has incoming nodes**.

If any node has **no incoming nodes** then that will be the **champion node.**

If **more than one node** has zero incoming nodes, we will **return -1.**

# Approach
1.) We will store the number of incoming edges/ **inorder** for each node in a vector.

        vector<int> inorder(n, 0);

        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];

            inorder[v]++;
        }

2.) We will traverse the vector and see that if any node satisfies the required condition.

3.) We will have a **"ans" variable**, **initially -1** which we will return at the end **after traversing in "inorder"** vector.

        int ans = -1;

        for(int i = 0; i < n; i++){
            //Logical code here
        }

4.) If while traversing, **ans is not "-1"**, means we have **found our champion** node. But if any **more node has zero inorder**, we will immediately **return -1**.

            if(ans != - 1 && inorder[i] == 0){
                return -1;
            }

5.) If **ans is "-1"** and current node has zero inorder, **we will store current node in ans**.

            if(ans == -1 && inorder[i] == 0){
                ans = i;
            }

6.) Return the ans.


# Complexity
- Time complexity:
O(n+e)

- Space complexity:
O(n)

*/

# Code
```cpp []
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> inorder(n, 0);

        //Calculating incoming edges/inorder
        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];

            inorder[v]++;
        }

        int ans = -1;

        for(int i = 0; i < n; i++){ 

            //More than 1 "champion" nodes
            if(ans != - 1 && inorder[i] == 0){
                return -1;
            }

            //Our first "champion" node
            if(ans == -1 && inorder[i] == 0){
                ans = i;
            }
            
        }

        return ans;
    }
};
```
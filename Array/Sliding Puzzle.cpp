/*
Leetcode 773:- Sliding Puzzle(hard)
# Intuition
We want to compare our input matrix elements with a fixed target, that is, "123450". **So the idea was to make a string of input matrix and compare it with "123450".**

**We want to swap elements only when adjacent element is "0". We can swap in any 4-directions -> Left, Right, Up, Down.**

So, by this reference, i got a hint of **"DFS" or "BFS"**.
# Approach
1.) Make a string of input matrix to compare with "123450".

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                compare += to_string(board[i][j]);
            }
        }
2.) We will be using BFS to perform required operations, so we will use **queue**. We will also use "**set**" data structure to keep track of strings which we have formed already.

**In queue, we will be storing string and number of steps to reach the current string.**

        queue<pair<string, int>> q;
        q.push({compare, 0});

        unordered_set<string> visited;
        visited.insert(compare);

3.) **We will do BFS until our target reaches or queue becomes empty.**

4.) If **queue becomes empty** and we have not return anything, this means **"123450" can not be formed so we will return -1.**

## 4-Directional Traversal in string

            //4- directional traversal

            /*
                    {column}
                   0   1   2
                   ___ ___ ___
                0 | 0 | 1 | 2 |
        {row}     ____ ___ ____
                1 | 3 | 4 | 5 |
                   ___ ___ ____

                These are locations of matrix[i][j] in linear form of 1-D array form{string form}

                If row = 1, col = 1 => we are at 4th index in our string
            
            */

/*           
So from the figure, we can observe these 4 conditions:-

 a.) **Up** :- We can't go up for 0th row . So we cant go up for 0, 1, 2 indexes in our string .
b.) **Down** :- We can't go down for 1st row. So, we can't go down for 3, 4, 5 indexes
c.) **Left** :- We can't go left for 1st column elements. So, we can't go left for 0, 3 indexes
d.) **Right** :- We can't go right for last column elements. So, we can't go right for 2, 5 indexes

**Note**:- ***Here index means index where '0' is present.***


# Complexity
- Time complexity:
O(6! x k) where k <= 4{direction}

- Space complexity:
O(number of sting formed) = O(6!)

*/

# Code
```cpp []
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        int rowSize = 2;
        int colSize = 3;

        string compare = "";
        string target  = "123450";

        //Making string of input matrix for comparison
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                compare += to_string(board[i][j]);
            }
        }

        queue<pair<string, int>> q; //String and number of count to reach this string
        q.push({compare, 0});//No steps done for compare string

        unordered_set<string> visited;//Not visiting same string again and again
        visited.insert(compare);


        while(!q.empty()){

            auto[curr_state, steps] = q.front();
            q.pop();

            if(curr_state == target){
                return steps;
            }

            int zero_index = -1;

            for(int i = 0; i < curr_state.size(); i++){
                if(curr_state[i] == '0'){
                    zero_index = i;
                    break;
                }
            }
            
            //Check if We have zero in matrix or not
            if(zero_index == -1){
                break;
            }

            //4- directional traversal

            //Up
            /*We can't go up for 0th row . So we cant go up for 0, 1, 2 indexes in our string */
            
            if(zero_index > 2){

                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index-3]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            //Down
            /* We can't go down for 1st row. So, we can't go down for 3, 4, 5 indexes */

            if(zero_index < 3){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index+3]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            //Left
            /* We can't go left for 1st column elements. So, we can't go left for 0, 3 indexes */

            if(zero_index != 0 && zero_index != 3){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index-1]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            //Right
            /* We can't go right for last column elements. So, we can't go right for 2, 5 indexes */

            if(zero_index != 2 && zero_index != 5){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index+1]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }
        }

        return -1;
    }
};
```
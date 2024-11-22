/*

Leetcode 1072:- Flip Columns For Maximum Number of Equal Rows(Medium)

# Intuition

**We want to check the maximum number of rows which are same in the matrix.** It can be before flipping the cell values or can be after flipping the cell values.

There is a line in the question which confused me **"You can choose any number of columns in the matrix and flip every cell in that column"**. 

**Basically it means we can flip a whole row.**

So , for storing previous value of a row before flipping bits, we will use **unordered_map**.

**It will store a key (string) and number of count(int).**

    unordered_map<string, int> mp;

# Approach

1.) **We will make a key of each row and store its count in the map.** If curent value of cell is "1", we will add "1" in string and vice versa.

2.) We will update the result, after updating count in map of each row.

      for(int i = 0; i < rowSize; i++){

            string temp = "";

            for(int j = 0; j < colSize; j++){

                int num = matrix[i][j];

                if(num){//num == 1
                    temp += "1";
                }
                else{// num == 0
                    temp += "0";
                }
            }

            mp[temp]++; 

            result = max(result, mp[temp]);//maybe already rows are same
        }

    
3.) We will do the 2 Step again, but we will do this time while flipping the bits. **This means we will make a key of flipped bits.**

        for(int i = 0; i < rowSize; i++){

            string temp = "";

            for(int j = 0; j < colSize; j++){

                int num = matrix[i][j];

                if(num){//num == 1, so after flipping it becomes 0
                    temp += "0";
                }
                else{//num == 0, so after flipping it becomes 1
                    temp += "1";
                }
            }

            mp[temp]++;

            result = max(result, mp[temp]);
        }

4.) Return the result
# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n)

*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        //Storing states 
        unordered_map<string, int> mp;

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int result = 0;

        //Calculating answer before flipping bits
        for(int i = 0; i < rowSize; i++){

            string temp = "";

            for(int j = 0; j < colSize; j++){

                int num = matrix[i][j];

                if(num){
                    temp += "1";
                }
                else{
                    temp += "0";
                }
            }

            mp[temp]++;

            result = max(result, mp[temp]);
        }

        //Calculating answer after flipping bits

        for(int i = 0; i < rowSize; i++){

            string temp = "";

            for(int j = 0; j < colSize; j++){

                int num = matrix[i][j];

                //Flipping the bits
                if(num){
                    temp += "0";
                }
                else{
                    temp += "1";
                }
            }

            mp[temp]++;

            result = max(result, mp[temp]);
        }

        return result;
    }
};
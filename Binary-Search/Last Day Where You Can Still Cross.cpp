/*
Leetcode 1970 :- Last Day Where You Can Still Cross(Hard)
Problem Breakdown:
You are given a grid with rows and columns of cells, initially empty. On subsequent days, some cells start getting flooded (represented by a 1 in the grid). Your goal is to find out the latest possible day when you can start from the top row and reach the bottom row without stepping into any flooded cell.

Key Concepts Used:
DFS (Depth-First Search): To traverse the grid and find a path from the top to the bottom row.
Binary Search: To efficiently find the latest day by using a search on days to determine the last possible day of crossing.
Code Explanation:
Variables and Directions:

Row and Col: Store the dimensions of the grid.
directions: Store the four possible movement directions (up, down, left, right) to traverse the grid.
Helper Functions:

isSafe: Checks if the current cell (row, col) is within bounds and if it's an empty cell (i.e., not flooded).
Dfs: A depth-first search function that checks if it's possible to traverse from the current cell to the last row. If a path to the last row is found, it returns true.
isPossible: This function simulates the grid state on a given day (mid). It updates the grid with flooded cells based on the input and tries to find a path using DFS. If a valid path exists on that day, it returns true.
Binary Search Logic (latestDayToCross):

The function performs a binary search on the possible days, starting with day 0 and ending with the last day in the input (cells.size() - 1).
For each day in the middle (mid), it uses isPossible to check if it's still possible to cross from the top to the bottom.
If a crossing is possible, it tries later days by moving the search range to the right (start = mid + 1).
Otherwise, it shifts the search to earlier days (end = mid - 1).
Final Output:

The final result is the latest day (days) when it's still possible to cross the grid.
Time Complexity:
Binary Search: O(log N), where N is the number of days.
DFS: O(R * C), where R is the number of rows and C is the number of columns (since DFS potentially visits every cell).
Total Complexity: O(log N * R * C)
Space Complexity:
O(R * C), since we're storing the grid and visited states in auxiliary space.

*/

class Solution {
public:

    int Row;
    int Col;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isSafe(vector<vector<int>> &grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1){
            return false;
        }
        return true;
    }

    bool Dfs(vector<vector<int>> &grid,int row, int col){
        if(!isSafe(grid, row, col)){
            return false;
        }

        if(row == grid.size() - 1){
            return true;
        }

        grid[row][col] = 1;

        for(auto &dir: directions){
            int x = row + dir[0];
            int y = col + dir[1];

            if(Dfs(grid, x, y)){
                return true;
            }
        }

        return false;
    }

    bool isPossible(vector<vector<int>> &cells, int mid){
        vector<vector<int>> grid(Row, vector<int>(Col, 0));

        // Block the cells from day 0 to mid
        for(int c = 0; c <= mid; c++){
            int i = cells[c][0] - 1;  // Use c instead of mid
            int j = cells[c][1] - 1;

            grid[i][j] = 1;
        }

        for(int j = 0; j < Col; j++){
            if(grid[0][j] == 0 && Dfs(grid, 0, j)){
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int start = 0;
        int end   = cells.size() - 1;

        Row = row;
        Col = col;

        int days  = 0;

        while(start <= end){

            int mid = start + (end - start)/2;

            if(isPossible(cells, mid)){
                days = mid + 1;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return days;
    }
};

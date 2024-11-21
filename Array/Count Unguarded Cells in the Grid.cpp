/*

Leetcode 2257 :- Count Unguarded Cells in the Grid(Medium)

#Intuition

The intuition was to fill a matrix such that we can see **guarded cells** and **unguarded cells.**
The idea was to build a **matrix of characters** where we will fill matrix:-

1.) If **guard cells**  -> 'G'
2.) If **wall cells**   -> 'W'
3.) If **guarded cells / safe cells** -> 'S'
4.) The **empty cells / unguarded cells** -> '.'

At last when we will fill the matrix, we will count number of unguarded cells or empty cells.
# Approach
1.) First we will build a matrix of "m" rows and "n" columns where **matrix[row][col] = "."**  {Empty}

        vector<vector<char>> matrix(m, vector<char>(n, '.'));

2.) We will fill guard cells and Wall cells.
    **Guard cells will be represnted by 'G' and wall cells by 'W'**.

        // Mark guards
        for (auto &guard : guards) {
            int row = guard[0];
            int col = guard[1];
            matrix[row][col] = 'G';
        }

        // Mark walls
        for (auto &wall : walls) {
            int row = wall[0];
            int col = wall[1];
            matrix[row][col] = 'W';
        }

3.) We will start our traversal in the matrix, if matrix[i][j] == 'G' then only we will mark all the row and columns as safe.


         // Fill guarded areas
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 'G') {
                    matrixFill(matrix, i, j, m, n);
                }
            }
        }

**Note**:-  In **matrixFill function** We will check if the cell we have reached is neither guard cell nor wall cell.
**If we have reached a guard cell or wall cell while filling the safe cells we will break from the loop.**

For exaomple if we are filling down rows then, :-

        // Down direction
        for (int i = row + 1; i < m; i++) {
            if (matrix[i][col] == 'W' || matrix[i][col] == 'G') 
                break;  // Stop at wall or guard

            matrix[i][col] = 'S'; //Mark safe by 'S'
        }

4.) We are not stopping when we are again visiting safe cell 'S', **this is because this cell could have been made safe by visiting from left to right and we are currently travsering from top to down.**

So if we stop by seeing 'S', then we will not be able to make all the cells of current columns safe, which will lead to wrong ans.


# Complexity
- Time complexity:
O(m*n) [Filling matrix]

- Space complexity:
O(m*n) [Matrix Space]

*/
class Solution {
public:

    void matrixFill(vector<vector<char>> &matrix, int row, int col, int m, int n) {
        
        // Down direction
        for (int i = row + 1; i < m; i++) {
            if (matrix[i][col] == 'W' || matrix[i][col] == 'G') 
                break;  // Stop at wall or guard

            matrix[i][col] = 'S'; //Mark safe by 'S'
        }

        // Right direction
        for (int j = col + 1; j < n; j++) {
            if (matrix[row][j] == 'W' || matrix[row][j] == 'G') 
                break; 

            matrix[row][j] = 'S';
        }

        // Up direction
        for (int i = row - 1; i >= 0; i--) {
            if (matrix[i][col] == 'W' || matrix[i][col] == 'G') 
                break;

            matrix[i][col] = 'S';
        }

        // Left direction
        for (int j = col - 1; j >= 0; j--) {
            if (matrix[row][j] == 'W' || matrix[row][j] == 'G')
                break; 

            matrix[row][j] = 'S';
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<char>> matrix(m, vector<char>(n, '.'));

        // Mark guards
        for (auto &guard : guards) {
            int row = guard[0];
            int col = guard[1];
            matrix[row][col] = 'G';
        }

        // Mark walls
        for (auto &wall : walls) {
            int row = wall[0];
            int col = wall[1];
            matrix[row][col] = 'W';
        }

        // Fill guarded areas
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 'G') {
                    matrixFill(matrix, i, j, m, n);
                }
            }
        }

        // Count unguarded cells
        int countUnguardedCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '.') {
                    countUnguardedCells++;
                }
            }
        }

        return countUnguardedCells;
    }
};

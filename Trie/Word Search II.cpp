/*

Leetcode 212 :- Word Search in a 2D Grid Using Trie(Hard)

Problem Overview
We are given a 2D grid of characters and a list of words. Our task is to find all the words from the list that can be formed by sequentially adjacent letters in the grid.

Approach Using Trie
A Trie is used to efficiently store all the words, allowing us to quickly prune invalid paths when searching through the grid. The Trie helps in managing backtracking and ensuring that we don’t revisit the same word multiple times.

Trie Structure for Words
Each node represents a character.
The end of a word is marked with a bool isEnd flag.
The node also stores the word, allowing us to retrieve the complete word once we find it in the grid.
Steps Explained
Insert Words into the Trie

Each word from the input list is inserted into the Trie, where each node corresponds to a letter. When we reach the end of a word, we mark the node as the end of that word and store the word.
Depth-First Search (DFS) with Backtracking

For each cell in the grid, we initiate a DFS.
At each step, we check if the current character exists in the Trie. If it does, we continue the search.
As we move to neighboring cells (up, down, left, right), we keep track of visited cells and backtrack when necessary.
If we reach a node marked as the end of a word, we add that word to the result list.

Efficiency

The Trie helps in pruning unnecessary searches. If a partial path in the grid doesn’t match any prefix in the Trie, we stop searching in that direction.
The search is efficient due to the Trie’s structure, where we only follow paths that could lead to valid words.

Explanation Recap:

Trie Insert: We insert each word into the Trie, building a tree-like structure where each letter of the word is a node.
DFS with Trie: For each cell in the grid, we start a DFS and use the Trie to check if a word can be formed. The Trie allows us to efficiently backtrack and prune invalid paths.

Advantages:
The Trie reduces the number of unnecessary searches by helping us determine early on if a path in the grid cannot form a valid word.
The solution efficiently finds all possible words without duplicating results.

*/

class Solution {
public:

    // Structure for TrieNode, used for storing the words in the Trie
    struct TrieNode {
        TrieNode* children[26];  // Each node has 26 children, one for each letter
        bool isEnd;              // Marks the end of a word
        string word;             // Stores the word at the end node
    };

    // Function to create a new TrieNode
    TrieNode* getTrieNode() {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < 26; i++) {
            root->children[i] = nullptr;  // Initialize all children as NULL
        }
        root->isEnd = false;
        root->word = "";
        return root;
    }

    // Function to insert a word into the Trie
    void insert(TrieNode* &root, string &word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';  // Convert letter to index (0 to 25)
            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = getTrieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;    // Mark the end of the word
        crawler->word = word;     // Store the word at the end node
    }

    // Function to perform DFS to search for words in the grid
    void dfs(TrieNode* root, int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] == '$') {
            return;  // Stop if out of bounds or already visited
        }

        int idx = board[row][col] - 'a';  // Convert letter to index
        if (root->children[idx] == nullptr) {
            return;  // If there's no matching child in the Trie, return
        }

        root = root->children[idx];  // Move to the next node in the Trie

        // If a word is found, add it to the result list
        if (root->isEnd == true) {
            ans.push_back(root->word);
            root->isEnd = false;  // To avoid duplicate words
        }

        char temp = board[row][col];
        board[row][col] = '$';  // Mark the cell as visited

        // Move in all 4 directions
        for (auto &dir : directions) {
            int x = row + dir[0];
            int y = col + dir[1];
            dfs(root, x, y, board);  // DFS call for the neighboring cells
        }

        board[row][col] = temp;  // Unmark the cell after visiting
    }

    // Function to find all words present in the 2D grid using Trie
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();

        TrieNode* root = getTrieNode();  // Initialize the Trie root

        // Insert all words into the Trie
        for (auto &word : words) {
            insert(root, word);
        }

        // Start DFS for each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (root->children[board[i][j] - 'a'] != nullptr) {
                    dfs(root, i, j, board);  // Start DFS from cell (i, j)
                }
            }
        }

        return ans;  // Return all found words
    }

private:
    vector<string> ans;  // To store the found words
    int n, m;            // Grid dimensions
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // 4 directions
};

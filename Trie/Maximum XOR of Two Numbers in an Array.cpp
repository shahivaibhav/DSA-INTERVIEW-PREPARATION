/*

Leetcode 421:- Finding Maximum XOR of Two Numbers Using a Trie(Medium)

Problem Overview
We are tasked with finding the maximum XOR (exclusive OR) of any two numbers from an array. XOR between two bits is 1 when the bits are different, and 0 when they are the same. Therefore, to maximize XOR, we need to pick numbers that have as many opposite bits as possible.

Approach Using Trie
The idea is to insert the binary representation of each number into a Trie. This allows us to compare the binary representations of numbers bit by bit. By traversing the Trie, we can efficiently find the number that, when XORed with the current number, gives the highest possible result.

Trie Structure
A Trie is a tree-like data structure where each node represents a single bit (either 0 or 1). The entire path from the root to a leaf represents a 32-bit binary number. In this solution:

Left child represents bit 0.
Right child represents bit 1.
Steps Explained
Insert Numbers into the Trie

Each number is treated as a 32-bit binary number (since the problem assumes the numbers fit within 32 bits).
We start from the most significant bit (31st bit) and go down to the least significant bit (0th bit).
For each bit, we traverse the Trie and create a new node if it doesn't exist, inserting the bit (either left for 0 or right for 1).
Find Maximum XOR

For each number, we traverse the Trie bit by bit, trying to go in the direction that maximizes XOR. If the current bit is 0, we try to go to the 1 branch (which would give us a higher XOR result), and vice versa.
At each step, we calculate the potential XOR by flipping bits and updating our maximum XOR result.

Efficiency

By using a Trie, each lookup to find the best XOR partner for a number is done in O(32), since we only need to check each bit of the number. This reduces the problem's complexity from O(n^2) (comparing every pair of numbers) to O(n) for insertion and comparison per number.

Explanation Recap:

Trie Insert: Insert all numbers in their binary form into the Trie.
Max XOR Search: For each number, traverse the Trie to find the number that maximizes XOR by trying to select opposite bits (e.g., if the current bit is 0, choose 1 to maximize the XOR).

Advantages:
By using a Trie, we reduce the complexity from O(n^2) (brute force pair comparison) to O(n) per number.
The solution ensures we find the maximum XOR efficiently even with large datasets.

*/

class Solution {
public:

    // TrieNode structure to represent binary bits (left for '0', right for '1')
    struct TrieNode {
        TrieNode* left;  // Represents bit '0'
        TrieNode* right; // Represents bit '1'
    };

    // Function to create a new TrieNode
    TrieNode* getTrieNode() {
        TrieNode* root = new TrieNode();
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    // Insert a number in the Trie, bit by bit (from most significant to least significant bit)
    void insert(TrieNode* &root, int num) {
        TrieNode* crawler = root;
        for (int i = 31; i >= 0; i--) {
            int ith_idx = (num >> i) & 1;  // Extract the ith bit
            if (ith_idx == 0) {            // If bit is 0, go left
                if (crawler->left == nullptr) {
                    crawler->left = getTrieNode();  // Create a new node if path does not exist
                }
                crawler = crawler->left;
            } else {                        // If bit is 1, go right
                if (crawler->right == nullptr) {
                    crawler->right = getTrieNode();
                }
                crawler = crawler->right;
            }
        }
    }

    // Find the maximum XOR by comparing each bit with its opposite in the Trie
    int findMaxi(TrieNode* &root, int num) {
        TrieNode* crawler = root;
        int temp = 0;  // To store the maximum XOR result
        for (int i = 31; i >= 0; i--) {
            int ith_idx = (num >> i) & 1;  // Extract the ith bit
            if (ith_idx == 0) {            // If bit is 0, try to move right (to get a 1)
                if (crawler->right != nullptr) {
                    temp += (1 << i);  // Add this bit to maximize XOR
                    crawler = crawler->right;
                } else {
                    crawler = crawler->left;
                }
            } else {                        // If bit is 1, try to move left (to get a 0)
                if (crawler->left != nullptr) {
                    temp += (1 << i);
                    crawler = crawler->left;
                } else {
                    crawler = crawler->right;
                }
            }
        }
        return temp;  // Return the maximum XOR for this number
    }

    // Main function to find the maximum XOR
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = getTrieNode();  // Initialize root of the Trie

        // Insert all numbers into the Trie
        for (int i = 0; i < nums.size(); i++) {
            insert(root, nums[i]);
        }

        int maxi = 0;

        // Find the maximum XOR for each number by comparing it with all others
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, findMaxi(root, nums[i]));
        }

        return maxi;  // Return the final maximum XOR
    }
};

/*

Leetcode 208:- Implement Trie (Prefix Tree)(Medium)

Detailed Explanation:
TrieNode Class:

The TrieNode class represents a single node in the Trie. Each node can have up to 26 children, one for each letter of the alphabet ('a' to 'z').
children[26]: An array of pointers to represent the children nodes. Each element corresponds to a character index ('a' maps to index 0, 'b' maps to 1, etc.).
isEnd: A boolean flag indicating whether a word ends at this node. This helps distinguish between words and prefixes.

Trie Class:

insert(string word):

Inserts a word into the Trie. For each character in the word, it traverses through the corresponding child node. If the child node is missing, it creates a new TrieNode.
Finally, it marks the last node as the end of the word using the isEnd flag.
search(string word):

Searches for a word in the Trie by traversing the nodes according to the characters in the word.
If a node corresponding to any character is missing, it returns false.
If all characters are found and the last node is marked as a word end (isEnd == true), it returns true.
startsWith(string prefix):

Checks if there is any word in the Trie that starts with the given prefix.
Similar to search, but it does not require the last node to be marked as a word end.
Time Complexity Analysis:
insert(string word):

Each insertion operation involves traversing the word length, l.
For each character, a constant-time operation is performed (checking and setting child pointers).
Time Complexity: 

O(l).
search(string word):

Each search operation involves traversing the word length, l.
For each character, a constant-time operation is performed (checking child pointers).

Time Complexity: 
O(l).
startsWith(string prefix):

Each operation involves traversing the prefix length, p.
For each character, a constant-time operation is performed (checking child pointers).

Time Complexity: 
O(p).


Space Complexity Analysis:

Space Usage for Trie Nodes:

Each node uses 26 pointers for children (TrieNode* children[26]).
Space complexity depends on the number of distinct characters inserted into the Trie.
Total Space Complexity:

For a given set of words, let L be the total length of all words.
Each character in L may need a separate node.
Space Complexity: 

O(26×L) = O(L).

*/

class TrieNode {
public:
    TrieNode* children[26]; // Array to store 26 children (for each alphabet letter)
    bool isEnd;             // Flag to indicate if a word ends at this node

    // Constructor to initialize children pointers and isEnd flag
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL; // Set all children pointers to NULL
        }
        isEnd = false; // Set the isEnd flag to false initially
    }
};

class Trie {
    TrieNode* root; // Root node of the Trie

public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* crawler = root; // Start from the root node

        // Traverse each character in the word
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a'; // Calculate the index for the character (0-25)

            // If the character node doesn't exist, create a new TrieNode
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = new TrieNode();
            }
            // Move the pointer to the child node corresponding to the character
            crawler = crawler->children[idx];
        }

        // Mark the end of the word
        crawler->isEnd = true;
    }

    // Function to search if a word is present in the Trie
    bool search(string word) {
        TrieNode* crawler = root; // Start from the root node

        // Traverse each character in the word
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a'; // Calculate the index for the character

            // If the character node is missing, word doesn't exist in the Trie
            if (crawler->children[idx] == NULL) {
                return false;
            }
            // Move the pointer to the child node corresponding to the character
            crawler = crawler->children[idx];
        }

        // Return true if this is the end of a word, otherwise false
        return crawler->isEnd;
    }

    // Function to check if any word in the Trie starts with the given prefix
    bool startsWith(string word) {
        TrieNode* crawler = root; // Start from the root node

        // Traverse each character in the prefix
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a'; // Calculate the index for the character

            // If the character node is missing, prefix doesn't exist in the Trie
            if (crawler->children[idx] == NULL) {
                return false;
            }
            // Move the pointer to the child node corresponding to the character
            crawler = crawler->children[idx];
        }

        // Return true if we can traverse the entire prefix without any missing node
        return true;
    }
};

/*
Leetcode 2300 :- Successful Pairs of Spells and Potions(Medium)

Problem Overview:
You are given two arrays: spells and potions. Each spell needs to be paired with a potion such that their product is greater than or equal to a given success value. You need to return the number of successful pairs for each spell.

Input:

spells – an array of integers representing the power of each spell.
potions – an array of integers representing the strength of each potion.
success – an integer value representing the threshold product needed.
Solution Approach:
Sort the Potions Array:
First, sort the potions array in ascending order.
Sorting helps in efficiently finding the first potion that, when paired with the given spell, satisfies the condition: spell * potion >= success.
Binary Search for Each Spell:
For each spell, find the first potion in the sorted potions array such that spell * potion >= success.
This is achieved using a binary search to locate the smallest index i where spell * potions[i] >= success.
Calculate Successful Pairs:
After finding this index i, the count of successful pairs for this spell is n - i, where n is the length of the potions array.
Store Results:
Store the result for each spell in a vector and return it.

Time Complexity Analysis:

Sorting the Potions Array:
Sorting the potions array takes O(n * log n), where n is the size of the potions array.
Binary Search for Each Spell:
For each spell in the spells array, we perform a binary search on the sorted potions array.

If m is the size of the spells array, the binary search takes O(m * log n).

Thus, the overall time complexity is O(n * log n + m * log n).

Space Complexity:

The space complexity is O(1) if we ignore the space needed for sorting.
If the sorting algorithm used is not in-place, then the sorting step might require O(n) extra space.
Additionally, the ans vector takes O(m) space to store the results.

*/

class Solution {
public:
    // Function to count the number of successful pairs of spells and potions
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> ans; // Stores the result
        int n = potions.size();
        sort(potions.begin(), potions.end()); // Sort the potions array for binary search

        // Iterate through each spell
        for (auto &spell : spells) {

            long long maxProduct = (long long)spell * (long long)potions[n - 1];

            // If the maximum possible product is less than the success threshold, no pair is successful
            if (maxProduct < success) {
                ans.push_back(0);
                continue;
            }

            // Binary search to find the first potion that satisfies the condition
            int start = 0;
            int end   = n - 1;

            while (start < end) {
                int mid = start + (end - start) / 2;
                long long product = (long long)spell * (long long)potions[mid];

                if (product >= success) {
                    end = mid; // Search in the left half for the first successful pair
                } else {
                    start = mid + 1; // Search in the right half
                }
            } 

            ans.push_back(n - end); // Number of successful pairs for this spell
        }
        return ans;
    }
};

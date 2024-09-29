/*
 Leetcode 374:- Guess Number Higher or Lower(Easy)

Problem:
You need to guess a number between 1 and n. The system provides feedback through a predefined API guess(int num), which returns:

-1 if your guess is higher than the picked number,
1 if your guess is lower, and
0 if you guessed the correct number.
Your goal is to find the picked number with the minimum number of guesses.

Approach:
To solve this problem, binary search is ideal. The idea is to repeatedly guess the number in the middle of the current search range, using the feedback to adjust the search bounds accordingly. This approach minimizes the number of guesses by halving the search space each time.

Why Binary Search?
In every iteration, you eliminate half of the search space. This ensures that the algorithm runs in O(log n) time, making it very efficient for large n.

Time Complexity: O(log n)
Space Complexity: O(1) (constant space used for variables)

*/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               0 if num is equal to the picked number
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;  // Start from 1
        int end = n;    // End at n

        // Standard Binary Search
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int result = guess(mid);  // Call the predefined API

            if (result == 0) {
                return mid;  // Found the correct number
            } else if (result == -1) {
                end = mid - 1;  // Guessed too high
            } else {
                start = mid + 1;  // Guessed too low
            }
        }
        return -1;  // This case won't happen as per problem constraints
    }
};

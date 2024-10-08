/*

Leetcode 2272 :- Substring With Largest Variance(Hard)

Explanation:

Initialize a Set of Characters:
Create a set st of unique characters in the string s.
Iterate Over All Pairs:
For every distinct pair (first, second) of characters in the set, try to find the maximum variance.
Count the Frequencies:
Use two counters first_count and second_count to track the frequencies of the two characters in the substring.
Reset Counts if Needed:
If second_count becomes greater than first_count, reset both counts because the variance cannot be negative.
Calculate the Variance:
If both counts are greater than zero, update the result with first_count - second_count.
If only first is present (second_count == 0) and second has been seen before (flag == true), calculate first_count - 1.
Return the Result:
Return the maximum variance found.

Time Complexity:

We iterate over all distinct pairs of characters (first, second) in the input string:
This results in a nested loop for pairs, leading to at most 26 * 26 = 676 combinations (as there are 26 lowercase letters).
For each pair, we traverse the string s exactly once, performing a linear scan.
The cost of a single linear scan is O(n).
Hence, the overall time complexity is O(676 * n), which simplifies to O(n) since 676 is a constant.

Space Complexity:
We use a few integer variables to store character counts, a set for the distinct characters, and the string itself.
The unordered_set can hold at most 26 distinct characters, which requires O(1) space.
No additional large data structures are created.
Hence, the space complexity is O(1).

So, the time complexity is O(n), and the space complexity is O(1).

*/

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();

        // Create a set to store unique characters from the string
        unordered_set<char> st(s.begin(), s.end());

        // Variables to count the frequency of two distinct characters
        int first_count = 0;
        int second_count = 0;
        int result = 0;
        bool flag = false;  // To track if the second character has been encountered before

        // Iterate over all possible pairs of distinct characters in the set
        for (char first : st) {
            for (char second : st) {
                if (first == second) continue;  // Skip if both characters are the same

                first_count = 0;     // Reset count for the first character
                second_count = 0;    // Reset count for the second character
                flag = false;        // Reset the flag for each character pair

                // Traverse the string to calculate the variance for the given pair of characters
                for (int i = 0; i < n; i++) {
                    char temp = s[i];

                    // Update counts based on the current character
                    if (temp == first) {
                        first_count++;
                    } else if (temp == second) {
                        second_count++;
                    }

                    // If the count of the second character exceeds the first, reset both counts
                    if (second_count > first_count) {
                        first_count = second_count = 0;
                        flag = true;  // We have encountered `second` before, so keep track
                    }

                    // Update result if both characters are present
                    if (first_count > 0 && second_count > 0) {
                        result = max(result, first_count - second_count);
                    }

                    // Handle the case when only `first` is present and `second` has been seen earlier
                    if (first_count > 0 && second_count == 0 && flag) {
                        result = max(result, first_count - 1);
                    }
                }
            }
        }

        return result;  // Return the maximum variance found
    }
};

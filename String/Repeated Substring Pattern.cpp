/*

Leetcode 459 :- Repeated Substring Pattern(Easy)

Explanation:

Divisor Check: The loop iterates over the potential lengths l starting from n/2 (the largest possible repeating pattern length). For each l, it checks if l is a divisor of n. If not, it skips to the next length.

Substring Extraction: If l is a divisor, the code extracts a substring temp of length l from the start of the string.

Repetition: It calculates how many times temp would need to be repeated (times = n/l) to construct the original string s.

String Construction: Constructs a new string res by repeating temp times number of times.

Pattern Match: If res is equal to the original string, it returns true.

Final Check: If no valid repeating pattern is found, the function returns false.

Time Complexity:

The outer loop iterates from n/2 down to 1. In the worst case, this is O(n/2) = O(n).
For each potential substring length l, we create a new string res by repeating the substring n/l times.
Constructing res involves appending the substring temp to res n/l times. The total time for constructing the string res is O(n) for each l.
Checking if res equals s takes O(n) time.
Hence, the overall time complexity is O(n^2), because we construct and compare the repeated substring up to n/2 times.

Space Complexity:

The space complexity is O(n) due to the temporary string res that we construct for each potential substring.
Other variables take O(1) space.
So, the time complexity is O(n^2), and the space complexity is O(n).

*/

class Solution {
public:
    // Function to determine if the given string can be constructed by repeating a substring pattern
    bool repeatedSubstringPattern(string s) {
        int n = s.length();  // Get the length of the input string

        // Iterate over possible lengths of the substring, starting from `n/2` down to `1`
        // The maximum possible length of the repeating substring is `n/2`
        for (int l = n / 2; l >= 1; l--) {
            
            // If the current length `l` is not a divisor of `n`, it cannot form a repeating pattern
            if (n % l != 0) continue;

            // Extract the candidate substring of length `l` from the start of the string
            string temp = s.substr(0, l);

            // Calculate the number of times this substring should repeat to match the entire string length
            int times = n / l;

            // Construct the repeated string using the `temp` substring
            string res = "";
            while (times--) {
                res += temp;
            }

            // Check if the constructed string `res` matches the original string `s`
            if (res == s) {
                return true;  // Found a repeating pattern, return `true`
            }
        }

        // If no repeating pattern is found, return `false`
        return false;
    }
};

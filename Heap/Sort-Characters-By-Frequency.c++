/*
Sort Characters By Frequency (LeetCode: 451) Medium

Problem:
Sort the characters of a string by their frequency in decreasing order.

Solution Explanation:

Count the frequency of each character using an unordered map.
Use a max-heap (priority queue) to store the characters by their frequencies.
Pop the characters from the heap and append them to the result string as many times as their frequency.

Time Complexity:

O(n log n) due to heap operations, where n is the length of the string.

Space Complexity:

O(n), space used by the heap and the frequency map.

*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto &it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty()) {
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            while (count--) {
                ans += ch;
            }
        }

        return ans;
    }
};

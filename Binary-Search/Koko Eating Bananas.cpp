/*
Leetcode 875:- Koko Eating Bananas(Medium)
Problem:
Koko loves to eat bananas, and there are multiple piles of bananas. You need to determine the minimum eating speed k such that Koko can finish eating all bananas within h hours.

Approach:
The goal is to minimize k (the speed at which Koko eats) using binary search. For each k, you calculate how long it would take Koko to eat all piles of bananas at that speed. Then, adjust start and end to minimize the speed.

Key Insight:

The binary search checks for each speed (k) whether Koko can eat all piles within the given time. This ensures that the solution is both efficient and correct.

Time Complexity: O(n log m)
Where n is the number of piles and m is the largest pile.
Space Complexity: O(1)

*/

class Solution {
public:
    // Check if Koko can eat all bananas at speed 'mid' within 'h' hours
    bool canEatAll(int mid, vector<int>& piles, int h) {
        int hours = 0;
        for (auto &pile : piles) {
            hours += pile / mid;  // Full piles
            if (pile % mid != 0) hours++;  // Add an extra hour for partial piles
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());  // Maximum speed is the size of the largest pile

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (canEatAll(mid, piles, h)) {
                end = mid;  // Try to lower the speed
            } else {
                start = mid + 1;  // Increase the speed
            }
        }

        return start;  // This is the minimum speed required
    }
};

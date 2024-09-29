/*

Leetcode 1537 :-  Minimum Time to Complete Tasks(Medium)
Problem:
Given an array where each element represents the time a worker takes to complete one task, and a target k representing the number of tasks to be completed, find the minimum time required to complete all tasks.

Approach:
The goal is to find the minimum time to complete exactly k tasks. For this, you use binary search to search for the minimum time, and for each mid-point of time, you check if the workers can complete k or more tasks within that time.

Key Insight:

Each worker can complete mid / num tasks in mid time. Using this function, the binary search checks if the number of completed tasks is at least k.

Time Complexity: O(n log(max_time))
Where max_time is the maximum possible time.
Space Complexity: O(1)

*/

class Solution {
public:
    typedef long long ll;

    // This function checks if it's possible to complete k tasks in 'mid' time.
    ll possible(ll mid, vector<int>& nums, int k) {
        ll total_tasks = 0;

        // Calculate how many tasks can be completed in 'mid' time.
        for (auto &num : nums) {
            total_tasks += mid / num;
        }

        return total_tasks;
    }

    long long minimumTime(vector<int>& nums, int k) {
        ll start = 1;
        ll end = (ll)(*min_element(nums.begin(), nums.end()) * (ll)k);

        // Binary search to find the minimum time
        while (start < end) {
            ll mid = start + (end - start) / 2;
            ll tasks_completed = possible(mid, nums, k);

            if (tasks_completed >= k) {
                end = mid;  // Try to minimize the time
            } else {
                start = mid + 1;  // Increase the time
            }
        }
        return start;
    }
};

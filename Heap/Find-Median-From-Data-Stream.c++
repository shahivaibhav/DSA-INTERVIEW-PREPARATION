/*

Median of Data Stream (LeetCode: 295) Hard

Problem:
Design a data structure that supports adding numbers from a data stream and finding the median of the current stream of numbers.

Solution Explanation:

Use two heaps:
A max-heap (maxi) to store the smaller half of the numbers.
A min-heap (mini) to store the larger half of the numbers.
Balance the two heaps such that maxi may contain at most one more element than mini.
The median is the top of the max-heap if the total number of elements is odd, or the average of the tops of both heaps if the total number is even.

Time Complexity:

addNum: O(log n)
findMedian: O(1)

Space Complexity:

O(n), where n is the number of elements in the stream.

*/

class MedianFinder {
public:
    priority_queue<int> maxi;  // Max-heap to store the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> mini;  // Min-heap to store the larger half

    MedianFinder() {}

    void addNum(int num) {
        if (maxi.empty() || num <= maxi.top()) {
            maxi.push(num);
        } else {
            mini.push(num);
        }

        if (maxi.size() > mini.size() + 1) {
            mini.push(maxi.top());
            maxi.pop();
        } else if (mini.size() > maxi.size()) {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        if (maxi.size() > mini.size()) {
            return maxi.top();
        }
        return (maxi.top() + mini.top()) / 2.0;
    }
};

/*
 Implement Queue using Stacks (LeetCode: 232) Easy
Problem:
Design a queue using two stacks. The queue should support the following operations efficiently:

push(x): Pushes an element x to the back of the queue.
pop(): Removes the element from the front of the queue.
peek(): Returns the front element of the queue.
empty(): Returns whether the queue is empty.
Solution Explanation:

Use two stacks: st1 for pushing new elements and st2 for popping/peeking elements.
When popping or peeking, transfer all elements from st1 to st2, perform the operation, and transfer the elements back to maintain order.

Time Complexity:

push: O(1)
pop and peek: O(n) (because of the stack transfer)

Space Complexity:

O(n), where n is the number of elements in the queue.


*/

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {}

    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int top = st2.top();
        st2.pop();

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    int peek() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int top = st2.top();

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    bool empty() {
        return st1.empty();
    }
};

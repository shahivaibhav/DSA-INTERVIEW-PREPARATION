/*
Problem No. 901(Medium)

Intuition:
The **StockSpanner** problem asks for the number of consecutive days (including the current day) the stock price was less than or equal to today's price. To efficiently compute this, a stack is used to maintain a record of stock prices and their spans in a monotonically decreasing order.
- Each time a new price comes in, we compare it with the prices on top of the stack. If the top of the stack has a price smaller or equal to the current price, it means the span of that price can be added to the span of the current price, as the current price breaks the streak of lower prices.
- This method ensures we only go through each element once, achieving an efficient solution.

Time Complexity: O(n)
- Each element is pushed and popped from the stack at most once, leading to a linear time complexity.

Space Complexity: O(n)
- The space used by the stack is proportional to the number of elements, which in the worst case is `n`, where `n` is the number of `next` calls.
*/

class StockSpanner {
public:

    // Stack stores pairs of {price, span}
    stack<pair<int, int>> st;

    // Constructor
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;  // Initialize span as 1 (the current day itself)

        // Pop all elements from the stack where the price is less than or equal to the current price
        while(!st.empty() && st.top().first <= price){
            // Accumulate the span of days with lower or equal prices
            span += st.top().second;
            st.pop();
        }

        // Push the current price and its span to the stack
        st.push({price, span});

        // Return the span for the current day
        return span;
    }
};

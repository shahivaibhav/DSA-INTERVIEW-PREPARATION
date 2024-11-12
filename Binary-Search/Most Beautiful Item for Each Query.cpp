
/*

Leetcode 2070:- Most Beautiful Item for Each Query(Medium)
Intuiton:-

--items[i][0] indicates price and items[i][1] indicates beauty.
--We want to return ans vector containing maximum beauty for particular query.
--The query vector has list of prices for which we want to find maximum beauty from items.
--The maximum beauty can be of a lower price.

For eg:- items = [[1,100], [2, 8]], query[1, 2] 
For this our ans = [100, 100] as upto price 2 our maximum beauty is 100.

So for this we can precalculate the maximum value upto certain points.
For this purpose we will sort the items vector.

Approach:-

1. Sort the items vector.
2. Precalculate the maximum beauty for every price.
3. Using standard binary search for optimally finding maximum beauty for each query.

m -> size of item vector, n -> size of query vector
Time complexity:-  
O(mlogm)[Sorting]
O(m)[Finding max Beauty before calculating ans]
O(nlogm)[Binary Search for each query]


Overall Time Complexity :- O((n+m)logm)

Space Complexity:- O(n)[Storing ans]


*/


class Solution {
public:

    int binarySearch(vector<vector<int>>& items, int query){
        
        int n     = items.size();

        int start = 0;
        int end   = n - 1;

        int ans = 0;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(items[mid][0] <= query){
                ans = items[mid][1];
                start = mid+1;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }


        int n = queries.size();
        vector<int> maxBeauty(n, 0);

        for(int i = 0; i < n; i++){
            int temp = binarySearch(items, queries[i]);

            maxBeauty[i] = temp;
        }

        return maxBeauty;
        
    }
};
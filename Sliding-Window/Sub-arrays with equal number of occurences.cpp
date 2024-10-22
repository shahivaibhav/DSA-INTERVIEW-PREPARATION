/*

GFG Problem :- Sub-arrays with equal number of occurences(hard)
Question-Link = [https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1]

Input: arr[] = [1, 2, 1] , x = 4 , y = 6
Output: 6
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1], x and y have same occurrence(0).
2) [2], x and y have same occurrence(0).
3) [1], x and y have same occurrence(0).
4) [1, 2], x and y have same occurrence(0).
5) [2, 1], x and y have same occurrence(0).
6) [1, 2, 1], x and y have same occurrence(0).

Approach

Intuition:-

After solving few examples, I got iniution of using two variables for storing count of respective element.

If count would be equal , i would just add (j - i + 1) as we do in classic sliding window problem.

But i was having isues and another thought of creating two more variables for seeing when was last time the elements found so that i will not skip the subarrays where elements are not present and still they change answer.

From here i was getting confused, but i got inution of prefix sum problem because concept is same.

So i tried prefix-difference + sliding window and it worked.

Time Complexity:-

O(n)

Space Compplexity:-

O(1)

*/

class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        
        int count_x = 0;
        int count_y = 0;
        
        unordered_map<int, int> mp;
        
        for(auto& el : arr){
            mp[el] = 0;
        }
        
        mp[0] = 1;

        int j = 0;
        int n = arr.size();
        
        int ans = 0;
        
        while(j < n){
            
            int el = arr[j];
            
            if(el == x){
                count_x++;
            }
            else if(el == y){
                count_y++;
            }
            
            int diff = count_x - count_y;
            
            if(mp.find(diff) != mp.end()){
                ans += mp[diff];
            }
            
            mp[diff]++;
            
            j++;
        }
        
        return ans;
        
        
    }
};
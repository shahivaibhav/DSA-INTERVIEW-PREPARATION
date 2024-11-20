/*

Leetcode 2516:- Take K of Each Character From Left and Right(Medium)

#Intuition
It is a standard sliding window problem where we need to find 
maximum window which can be deleted so that the remaining substring contains 
atleast "k" number of "a", "b", and "c".

#Approach

1.) We will count the frequency of "a", "b", and "c". If initially any of the count is less than "k" we will return -1.

2.) We will use proper sliding window approach, that means we will have "i" and "j" pointers for traversing.

3.) While visiting any element we will decrease it's count, that means

        if(s[j] == 'a'){
            count_a--;
        }
        else if(s[j] == 'b'){
            count_b--;
        }
        else{
            count_c--;
        }

4.) We will check if any of the count is less than "k" then we will shrink the current window until count is equal to "k" or "i" and "j" are equal.

    while(i <= j && (count_a < k || count_b < k || count_c < k)){
        if(s[i] == 'a'){
            count_a++;
        }
        else if(s[i] == 'b'){
            count_b++;
        }
        else{
            count_c++;
        }
        i++;
    }

5.) We will calculate maximumWindowToDeleted which will be the length of window => j - i + 1.

6.) After Traversal we will return remaining length of string, that is
n - maximumWindowToDeleted

#Time complexity:
O(n)

#Space complexity:
O(1)

*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                count_a++;
            }
            else if(s[i] == 'b'){
                count_b++;
            }
            else{
                count_c++;
            }
        }

        if(count_a < k || count_b < k || count_c < k){
            return -1;
        }

        int i = 0;
        int j = 0;

        int maxWindowToDeleted = -1;

        while(j < n){

            if(s[j] == 'a'){
                count_a--;
            }
            else if(s[j] == 'b'){
                count_b--;
            }
            else{
                count_c--;
            }

            while(i <= j && (count_a < k || count_b < k || count_c < k)){
                if(s[i] == 'a'){
                    count_a++;
                }
                else if(s[i] == 'b'){
                    count_b++;
                }
                else{
                    count_c++;
                }
                i++;
            }

            maxWindowToDeleted = max(maxWindowToDeleted, j - i + 1);
            j++;

        }

        return n - maxWindowToDeleted;
    }
};
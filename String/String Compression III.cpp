/*
    Leetcode 3163 : String Compression III(Meadium)
    Inuition:-

    After reading the problem and example, we can understand that we have to count the number of continuous occurences of any character.
    Also if count reaches 9, we have to restart our counting.

    So we can achieve this by normal linear traversal where we will be counting each character and increase count if previous character was same to current character.

    Approach:-
    We can define a variable "prev" which will be storing the previous character when we will be traversing in the input string.
    Initially prev will be empty.

    Also a variable "count" will be used for counting.
    Intially count will be 0.

    Edge case:-
    If our traversal gets completed and we have not added the last element -> which means "prev" is not empty, then we will add it also in our ans string.

    Time Complexity  - O(n)[Linear traversal in string]
    Space Complexity - O(n)[For storing ans string]

*/

class Solution {
public:

    string compressedString(string word) {
        
        string ans = "";
        int count  = 0;
        int n      = word.length();

        char prev = ' ';

        for(int i = 0; i < n; i++){

            if(prev == ' '){
                count = 1;
                prev = word[i];
            }
            else if(word[i] == prev){
                count++;
                if(count == 9){
                    ans += to_string(count) + prev;
                    prev = ' ';
                }
            }
            else{
                ans += to_string(count) + prev;
                prev = word[i];
                count = 1;
            }
        }

        if(prev != ' ')
            ans += to_string(count) + word[n-1];

        return ans;
    }
};
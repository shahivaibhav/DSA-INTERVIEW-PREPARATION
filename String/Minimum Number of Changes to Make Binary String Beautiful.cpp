/*
Leetcode 2914 :- Minimum Number of Changes to Make Binary String Beautiful(Medium)

Intution:- 

After reading the problem statement and example :-
1.) Our input will always be of even length.
2.) We have to flip the bits only when we want to make the subarray of even length {2, 4, ....} of only zeroes or ones.

So, the problem can be broken as:-
Number of flips to make subarray of size 2 of only ones or zeroes.

This is because we want to make even subarrays so we will always be looking in window of size 2.

Approach:-

We will traverse in the input string and for window of size 2, we will count number of zeroes and ones.
If number of zeroesCount or onesCount are 2 -> meaning we do not need to change any bit.
Else we will flip one bit to convert zero to one or vice versa.

Time Complexity  :- O(n)
Space Complexity :- O(1)

*/


class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length();

        int i     = 0;
        int flips = 0;

        while(i < n){

            int countZero = 0;
            int countOne = 0;

            for(int count = 1; count <= 2; count++){

                if(s[i] == '0')
                    countZero++;
                else
                    countOne++;
                i++;
            }

            if(countZero == 0){
                continue;
            }
            
            if(countOne == 0){
                continue;
            }

            flips++;
        }

        return flips;

    }
};
 /*
    Leetcode 1611:- Minimum One Bit Operations to Make Integers Zero(Hard)

        Left to Right or Right to Left?

        --If we traverse from right to left we will have to traverse again and again 
            due to 2 condition of problem statement.

        -- Ex:- If we want to convert 11 to 00 then:-
            11 becomes 10(1 condition of problem states 0th bit can be converted to 0 without any condition)
            Now to make 10 to 00 we have to set 0th bit 1 as 2 condition of problem states it can be set to 0 if (i-1)th bit is 1
            But we have already converted it into 0 so again we will convert it into 1 and so on..

        Hence we will traverse from Left to Right.

        Logic Building:-

        The question is too hard and so i used hint given by leetcode to make my approach.
        The hint suggested to first try to find solution for 2^k nums.
        Basically we should try from 100, 1000, 10000... and so on.

        Let's  take example 1000 and 100

        To convert 100 to 000 No. of steps required = 5 
        
        1. 100 => 110
        2. 110 => 010
        3. 010 => 011
        4. 011 => 001
        5. 001 => 000

        Sly, for 1000 i got ans = 11

        If we want to set ith bit of n, by observation formula derived was:-
        F(ith bit set) = 2 * F(ith - 1) + 1;

        What i mean by ith bit set to 1 is in example of 100, at i = 2 our ith bit is set.
        Sly for 1000 , at i = 3 our bit is set.

        F(3) = 2 * F(3-1) + 1 => 2 *F(2)+1 => 2 * 5 + 1
          11 = 11... So this formula works and you can try few examples on your own.\

        Main part of question:-

        How to find answer for 11010?
        We know in how many steps we can convert 10000 to 00000 by formula.
        Also We know in how many steps we can convert 1010 to 0000 by formula and so on.

        If we see in conversion of 10000 to 00000, we will have to convert 10000 to 11000 as described before.

        No. of steps Required for converting 10000 to 00000 = x
        No. of steps Required for converting 1000 to 0000 = y

        No. of extra steps = x - y
        Meaning for conversion of 11010 to 00000
        we can solve F(11010) = F(10000) - F(1010)
                    F(11010) = F(10000) - (F(1000) - F(10))
                    

        So we can derive formula such as first value added then second subtracted than third added and so on..

        There can be 31 bits so we will store no. of steps already in some vector

        Time Complexity:- 
        O(1)

        Space Complexity:-
        O(1)
    */


class Solution {
public:

   

    int minimumOneBitOperations(int n) {
        
        vector<long long> store(32, 0);

        store[0] = 1;

        //Storing no. of steps for each ith bit
        for(int i = 1; i <= 31; i++){
            store[i] = 2 * store[i-1] + 1;
        }

        //For subtraction or addition
        bool sign = true;

        int res = 0;

        for(int i = 31; i >= 0; i--){

            int ith_bit = (1 << i) & n;

            //Our answer depends on setting 1 only
            if(ith_bit == 0){
                continue;
            }

            if(sign){
                res += store[i];
            }
            else{
                res -= store[i];
            }

            sign = !sign;

        }

        return res;
    }
};
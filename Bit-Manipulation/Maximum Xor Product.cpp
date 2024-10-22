
    /*

    Leetcode 2939:- Maximum Xor Product(Medium)

    
    We have to find out the max value of x such that (a^x)  * (b^x) is maximised

    Basics to know before Proceeding:-

    1. If we want to find the ith bit of any element we can find it by:-
        ith_bit = (element >> i) & 1;

        where element is the element whose ith bit we want to find,
        i is the index(ith bit)
        
        When we right shift the element by its index(for finding ith bit) and perform and operation with it we get the ith bit.

    2. If i have 1 , in binary lets say 001 and i want 1 bit at index no 1 from right to be 1, we can perform left shift operation.
        
        one_at_i_index= (1 << i);

        so it becomes 010

    3.  0 xor 0 = 0
        1 xor 1 = 0
        0 xor 1 = 1
        1 xor 0 = 1

    How To maximise?

    If we have to maximise binary no. 0001 it can be maximum 1111 so basically by maximising we mean to add 1 to the ith bit.

    This Question and its logic:-
    
    Lets say a_xor = (a ^ x) and b_xor = (b ^ x);

    This question can be divided into two parts:-

    a.) Finding ith bit of a_xor & b_xor from 49(question say max n = 50) to n
    b.) Finding ith bit of a_xor & b_xor from n-1 to 0

    as our answer wont be affected by 49 to nth bit so we will calculate it separately.
    
    //Finding ith bit of a_xor & b_xor from n-1 to 0
    This is tricky:-

    --If ith bit of both a and b are same  then a_xor & b_xor can be converted to 1 by left shifting property
    --If they are not same then using math logic we will try to increase smaller number 
        Ex- a = 14, b = 6
        if(a is incresed => a = 15)
        15 * 6 = 90

        if(b is increased => b = 7)
        14 * 7 = 98

        Hence we will increase smaller no's xor

    Time Complexity:- 0(50)
    Space Complexity:- 0(1)
    */

    

class Solution {
public:
typedef long long ll;

    int maximumXorProduct(long long a, long long b, int n) {
        
        ll a_xor = 0;
        ll b_xor = 0;

        ll x = 0;

        /*First Part*/
        for(ll i = 49; i >= n; i--){

            bool a_ith = ((a >> i) & 1) > 0;// We want to only do logic if our ith bit is 1 as 0 wont affect anything so we will save extra time
            bool b_ith = ((b >> i) & 1) > 0;

            if(a_ith){
                a_xor ^= (1ll << i);
            }

            if(b_ith){
                b_xor ^= (1ll << i);
            }
        }

        /*Second Part*/
        for(ll i = n - 1; i >= 0; i--){

            bool a_ith = ((a >> i) & 1) > 0; 
            bool b_ith = ((b >> i) & 1) > 0;

            if(a_ith == b_ith){
                a_xor ^= (1ll << i);
                b_xor ^= (1ll << i);
                continue;
            }
            else{
                if(a_xor > b_xor){
                    b_xor ^= (1ll << i);
                }
                else{
                    a_xor ^= (1ll << i);
                }
            }

        }

        int mod = 1e9 + 7;

        a_xor = a_xor % mod;
        b_xor = b_xor % mod;

        return ((ll)a_xor * (ll)b_xor)%mod;
    }
};
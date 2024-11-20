/*

Leetcode 87:- Scramble String(Hard)

# Intuition
There was no clear intution until i myself dry run this example of leetcode.

s1 = "great", s2 = "rgeat"

Here s1 can be converted to s2 when we do a partition of length 2 on s1, then 
s1 = "gr" + "eat"
If we further do a partition of length 1 on "gr", it becomes "g" + "r"

Now if we swap these two, so current string becomes "rg"
So, s1 = "rg" + "eat" = "rgeat" = s2

So, here we are partionining at each level from Length = 1 to less then length of string.

So, from here i got hint of **MATRIX CHAIN MULTIPLICATION(MCM)**.


# Approach
The current problem has 2 states :-

-- Swapped State
-- Not Swapped State

#### Not Swapped State:-
When we are not swapping the characters of string s1, then we can directly compare it with s2.

s1 = "great", s2 = "rgeat"
So, let's assume we have done a partion of length 2.
s1 = "gr" + "eat"

So this string s1 has now **2 halves**, left half of length 2, and right half of length 3.
So we will be comparing left and right halves of s1 with s2.

Left half of s1 should be equal to left half of s2 and sly for right half.

**Left Half** :- s1.substr(0, length) , s2.substr(0, length) //Length is partion Length
**Right Half** :- s1.substr(length, remainingLength), s2.substr(length, remainingLength)

***So basically we are comparing "gr" of s1 with "rg" of s2 and "eat" of s1 with "eat" of s2.***

#### Swapped State:-

When we are swapping the characters of string s1, then we compare it with s2.

s1 = "great", s2 = "rgeat"
So, let's assume we have done a partion of length 2.
s1 = "gr" + "eat"
Now we swap these two halves
s1 = "eat" + "gr"

So this string s1 has now **2 halves**, left half of length 3, and right half of length 2.
So we will be comparing left and right halves of s1 with s2.

As we have swapped the halves of s1, so we will be comparing left half of s1 of length 3 with right half of s2 with length 3 and right half of s1 of length 2 with left half of s2 of length 2.

**Note** :- While comparing, the lengths of compared strings should always be equal then only we can compare them.
Ex- We can not compare "gre" with "gr" as length are not same.

Let's say we have done a partition at "i" length, and length of string is n.
So **remaining Length = n - i**

**Left Half** :- s1.substr(0, i), s2.substr(n-i, i) // Left half of s1 of length "i" with right half of s2 of length "i"
**Right Half** :- s1.substr(i, n-i) , s2.substr(0, n-i) // Right half of s1 of remaining length (n-i) with left half of s2 of length "n-i"

***So if after swapping s1 = "eatgr" , and s2 remains same = "rgeat"
we will be commparing "eat" of s1 with "eat" of s2 and "gr" of s1 with "rg" of s2.***

## Base Case :-

1.) If length of 2 input strings are not equal then we can't compare hence **return false;**
2.) If both strings are equal then we r**eturn true**.

        if(s1 == s2){
            return true;
        }

        if(s1.length() != s2.length()){
            return false;
        }


## **MEMOISATION**
We would be use unordered map to store the states.

        unordered_map<string, bool>mp;

We will be making keys of input string like

        string key = s1 + "-" + s2;

This will help us to find the state if we have previously visited this state and if not then we will store the result for this state in map.

# Complexity
- Time complexity:
O(n^5)
- Space complexity:
O(n^4)

*/

class Solution {
public:

    unordered_map<string, bool> mp;

    bool isPossible(string s1, string s2){

        if(s1 == s2){
            return true;
        }

        if(s1.length() != s2.length()){
            return false;
        }

        string key = s1 + "-" + s2;

        if(mp.find(key) != mp.end()){
            return mp[key];
        }

        int n       = s1.length();
        bool result = false;

        for(int i = 1; i < n; i++){

            /*s1 = "great", s2 = "rgeat"*/

            bool without_swapped = isPossible(s1.substr(0, i), s2.substr(0, i)) && 
                                    isPossible(s1.substr(i, n-i), s2.substr(i, n-i));

            if(without_swapped){
                result = true;
                break;
            }

            bool swapped = isPossible(s1.substr(i, n-i), s2.substr(0, n-i)) && 
                                    isPossible(s1.substr(0, i), s2.substr(n-i, i));

            if(swapped){
                result = true;
                break;
            }
        }

        return mp[key] = result;

    }

    bool isScramble(string s1, string s2) {
        
        mp.clear();
        return isPossible(s1, s2);

    }
};
/*

    Gfg Problem :- Modify the Array(Easy)

    Question Link:- [https://www.geeksforgeeks.org/problems/ease-the-array0633/1]

    Problem Statement:- Given an array arr. Return the modified array in such a way that if the current and next numbers are valid numbers and are equal then double the current number value and replace the next number with 0. After the modification, rearrange the array such that all 0's are shifted to the end.

    Note:

    Assume ‘0’ as the invalid number and all others as a valid number.
    The sequence of the valid numbers is present in the same order.

    Input: arr[] = [2, 2, 0, 4, 0, 8] 
    Output: [4, 4, 8, 0, 0, 0] 
    Explanation: At index 0 and 1 both the elements are the same. So, we will change the element at index 0 to 4 and the element at index 1 is 0 then we will shift all the zeros to the end of the array. So, the array will become [4, 4, 8, 0, 0, 0].

    Input: arr[] = [0, 2, 2, 2, 0, 6, 6, 0, 0, 8] 
    Output: [4, 2, 12, 8, 0, 0, 0, 0, 0, 0]
    Explanation: At index 5 and 6 both the elements are the same. So, we will change the element at index 5 to 12 and the element at index 6 is 0. We will change the element at index 1 to 4 and the element at index 2 is 0. Then we shift all the zeros to the end of the array. So, array will become [4, 2, 12, 8, 0, 0, 0, 0, 0, 0].

    **Approach:-

    This question can be divided into two parts:-
    1.) When adjacent duplicates element are found, double the previous element and convert 0 to current element
    2.) Move Zeroes to end
    
    --First Part--
    First part is very easy as we have to only double the element and make zero to other one.
    We can do this in one pass by traversing from index 1 to last index.
    
    We start from index 1 as we want to check if pervious element is duplicate or not.
    
    
    --Second Part--
    This is a separate question in itself:-
    [https://leetcode.com/problems/move-zeroes/description/]
    
    This can also be achieved by using 2 Pointer technique
    
    "i" pointer keeps check of non zeroes element
    "j" pointer for zeroes
    
    -if our arr[i] is 0 and arr[j] is not 0 something like [1, 0, 4...] i = 0, j = 1
    we will swap arr[i] and arr[j] and move pointers further(i++, j++)
    
    -if our arr[i] is non zero and arr[j] is 0 something like [4, 0, 5, ..] i = 0, j = 1
    we will increase only i pointer as i pointer is only for indicating zeroes
    
    -- if not above cases:- meaning both elements are 0 so we will increase jth pointer only
    
    Time Complexity:- O(n)
    Space Complexity:- O(1)

*/


class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        
        //Changed to 0's
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]){
                int num = arr[i];
                
                if(num == 0){
                    continue;
                }
                
                arr[i-1] = 2 * num;
                arr[i] = 0;
            }
        }
        
        //Zeros at end;
        
        int i = 0;
        int j = 1;

        while(i < n && j < n){
            
            if(arr[i] == 0 && arr[j] != 0){
             
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if(arr[i] != 0 && arr[j] == 0){
                i++;
            }
            else{
                j++;
            }
        }
        
        return arr;
    }
};
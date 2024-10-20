
/*

Leetcode 798:-  Smallest Rotation with Highest Score(Hard)

original = [2,3,1,4,0]

            Rotate by left as question says

            rotate=>0= [2,3,1,4,0] => [0, 0, 1, 0, 1]
            idx      = [0,1,2,3,4]

            rotate=>1= [3,1,4,0,2] => [0, 1, 0, 1, 1]
            idx      = [0,1,2,3,4]

            rotate=>2= [1,4,0,2,3] => [0, 0, 1, 1, 1]
            idx      = [0,1,2,3,4]

            rotate=>3= [4,0,2,3,1] => [0, 1, 1, 1, 1]
            idx      = [0,1,2,3,4]

            rotate=>4= [0,2,3,1,4] => [1, 0, 0, 1, 1]
            idx      = [0,1,2,3,4]

            number                            = 2 3 1 4 0
            starts contibuting after rotation = 1 2 3 4 4
            ends contibuting  at rotation     = 4 4 2 0 0
            

            after observation 

            starting formula can be achieved as [possible start]  lower_bound = (i + 1) % n;
            ending   formula can be achieved as [possible end]   upper_bound = (i - nums[i] + n + 1) % n;

            Intuion of lower and Upper-Bound:-

            1.) we want to calculate at lowest rotation where given no. start contributing to ouer answer.
            2.) Also we were looking for highest rotation where given no. ends contibuting

            For lowest rotation -> lower_bound
            For Highest Rotation -> upper_bound

            Dont confuse with binary Search Lower Bound and Upper bound; 
            It's just naming.

   Time Complexity: O(n) because we are making a single pass to calculate initial contributions and then updating the score for each possible rotation.
   
    Space Complexity: O(n) due to the contributions array that keeps track of score changes across rotations.
        


*/

class Solution {
public:
    int bestRotation(vector<int>& nums) {

        int n = nums.size();
        vector<int> contributions(n, 0);

        int total_score = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] <= i){
                total_score++;
            }

            int start_idx = (i + 1) % n;
            int end_idx   = (i - nums[i] + n + 1) % n;

            contributions[start_idx]++; // As it contibutes at start_idx

            if(end_idx < n){
                contributions[end_idx]--;
            }

            // The cases where [2,3,1,4,0] start_idx of 1 was 3 and end_idx was 2
            // Means already contributing
            // So for prevention only increase count at 0 index only;
            // Because we are sure that at 0 index it will be definitelty contibuting 
            // if a case occurs where number was present on index 1 so at 0 index it will contibute
            // We are not sure of at which particular index it is so we will increase only of 0 index
            if(start_idx > end_idx){
                contributions[0]++; 
            }

        }

        int maxi_score = total_score;
        int curr_score = total_score;

        int k_rotations = 0;

        for(int i = 0; i < n; i++){
            curr_score += contributions[i];

            if(curr_score > maxi_score){
                maxi_score = curr_score;
                k_rotations = i;
            }
        }

        return k_rotations;
       
    }
};
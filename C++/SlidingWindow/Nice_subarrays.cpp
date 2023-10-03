// LEETCODE SLIDING WINDOW PROBLEM 1 - https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0;
        int odd = 0;
        int count = 0;
        int total = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 != 0){
                odd++;
                if(odd >= k){
                    count = 1; //set count as 1
                    while (!(nums[j++] & 1)) count++;
                    // while (j < i && nums[j] % 2 == 0){
                    //     count++;
                    //     j++;
                    // }
                    total += count;
                }
            } else if (odd >= k) total += count;       
        }
        return total;
    }
};
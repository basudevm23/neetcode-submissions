class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // for solving this problem in linear time, which means no data structure
        int res = nums[0];
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!= res){
                count--;
            }
            else count++;

            if(count<0) count = 0;

            if(count == 0){
                res = nums[i];
            }
        }


        return res;
    }
};
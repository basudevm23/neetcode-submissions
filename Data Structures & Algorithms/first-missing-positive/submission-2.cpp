class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n =nums.size();

        for(int i=0; i< nums.size(); i++){
            if(nums[i] < 0) nums[i] = 0;
        }

        for(int i=0; i<n; i++){
            int val = abs(nums[i]) - 1;

            if(val < nums.size() && val>=0){
                if(nums[val] > 0) nums[val] = nums[val] * -1;
                if(nums[val] == 0) nums[val] = -1*(nums.size()+1);
            }
        }

        for(int i=1; i<=nums.size(); i++){
            if(nums[i-1]>=0){
                return i;
            }
        }
        return nums.size()+1;


    }
};
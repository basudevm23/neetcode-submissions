class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        int currsum = 0;
        for(int i=0; i<n; i++){
            currsum = currsum + nums[i];
            maxsum = max(currsum, maxsum);
            if(currsum<0){
                currsum = 0;
            }            
        }
        // curr = -1, max=2
        return maxsum;        
    }
};

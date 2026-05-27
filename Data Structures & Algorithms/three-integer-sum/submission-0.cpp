class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
                // we dont want to resue the same value again and again
            }
            int left = i+1;
            int right = n-1;
            while(left<right){
                int threesum = nums[i]+nums[left]+nums[right];
                if(threesum>0){
                    right--;
                }
                else if(threesum<0){
                    left++;
                }
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }            
                }
            }
        }
        return ans;
    }
};

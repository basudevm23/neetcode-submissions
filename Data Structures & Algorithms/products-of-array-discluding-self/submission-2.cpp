class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        int prefixx = 1;
        for(int i=0; i<n; i++){
            prefix[i] = prefixx;
            prefixx = prefixx*nums[i];
// 1, 1, 2, 8
        }
        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            prefix[i] = prefix[i]*suffix;
            suffix = suffix*nums[i];       
        }
        // 48, 24,12,8
        return prefix;
    }
};

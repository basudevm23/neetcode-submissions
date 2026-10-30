class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(auto num: nums){
            ans = ans^num;
        }
        return ans;
    }
};

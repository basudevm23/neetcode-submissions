class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());

        int sum = 0;
        for (int i = 0; i < prefix.size(); i++) {
            prefix[i] = nums[i] + sum;
            sum = prefix[i];
        }
        int count = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == k) count++;
        }

        for(int i = 1; i < prefix.size(); i++){
            if(prefix[i]==k) count++;
        }

        for (int i = 1; i < prefix.size(); i++) {
            for (int j = i+1; j < prefix.size(); j++) {
                if ((prefix[j] - prefix[i - 1]) == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
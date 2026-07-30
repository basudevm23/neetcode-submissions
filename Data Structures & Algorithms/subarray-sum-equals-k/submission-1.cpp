class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        // key: prefixSum and its value: frequency

        mpp[0]=1;
        int count = 0;
        int currSum = 0;

        for(int i = 0; i<nums.size(); i++){
            currSum = currSum + nums[i];
            int diff = currSum - k;

            if(mpp.find(diff)!=mpp.end()){
                count += mpp[diff];
            }
            if(mpp.find(currSum) == mpp.end()){
                mpp[currSum] = 1;
                continue;
            }

            mpp[currSum]++;
        }
        return count;
    }
};
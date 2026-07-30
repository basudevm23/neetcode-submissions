class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = nums.size()/3;

        vector<int> res;
        unordered_map<int, int> mpp;
        for(int num: nums){
            if(mpp.find(num)!=mpp.end()){
                mpp[num]++;
                continue;
            }
            mpp[num] = 1;
        } 

        for(auto [key, value]: mpp){
            if(value>k){
                res.push_back(key);
            }
        }
        return res;
    }
};
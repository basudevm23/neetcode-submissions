class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<n;i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=1;
            }
            else{
                mpp[nums[i]]++;
            }
        }
        vector<vector<int>> bucket(n+1);
        for(auto& [key, value]: mpp){
            bucket[value].push_back(key);
        }
        vector<int> ans;
        for(int i=n; i>=0; i--){
            for(int j=0; j<bucket[i].size(); j++){
                ans.push_back(bucket[i][j]);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};

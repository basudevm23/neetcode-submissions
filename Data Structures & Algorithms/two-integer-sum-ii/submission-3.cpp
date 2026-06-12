class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp;
        int n = numbers.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int reqd = target - numbers[i];
            if(mpp.find(reqd)!=mpp.end()){
                ans.push_back(mpp[reqd]+1);
                ans.push_back(i+1);
            }
            mpp[numbers[i]] = i;
        }   
        return ans;  
    }
};

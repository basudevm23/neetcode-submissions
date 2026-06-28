class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& final, vector<int>& res, vector<bool>& pick){
        if(res.size()==nums.size()){
            final.push_back(res);
            return;
        } 

        for(int i=0; i< nums.size(); i++){
            if(!pick[i]){
                pick[i] = true;
                res.push_back(nums[i]);
                backtrack(nums, final,res, pick);
                res.pop_back();
                pick[i] = false;
            }
        }                     
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        // initial we have 3 choices then 2 and then 1 
        // put the element at the front or at the back

        vector<bool> pick(nums.size(), 0);
        vector<int> res;
        vector<vector<int>> final;

        backtrack(nums, final,res, pick);
        return final;
        
    }
};

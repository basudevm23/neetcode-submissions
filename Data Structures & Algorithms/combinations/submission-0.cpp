class Solution {
    vector<vector<int>> res;
public:
    void backtrack(int index, vector<int>& nums, vector<int>& temp, int k){
        if(index == nums.size()){
            if(temp.size() == k){
                res.push_back(temp);
            }
            return;
        }
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        backtrack(index+1, nums, temp, k);
        temp.pop_back();
        backtrack(index+1, nums, temp, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n, -1);
        
        for(int i =0; i<nums.size(); i++){
            nums[i] = i+1;
        }
        vector<int> temp;

        backtrack(0, nums, temp, k);
        return res;
    }
};
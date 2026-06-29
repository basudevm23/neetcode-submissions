class Solution {
    vector<vector<int>> res;
public:
    void subsetting(int index,vector<int>& nums, vector<int>& temp){
        if(index>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        

        subsetting(index + 1, nums, temp);
        temp.pop_back();
        while(index+1 < nums.size() && nums[index + 1] ==nums[index]){
            index++;
        } 
        subsetting(index + 1, nums, temp);  
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        subsetting(0, nums, temp);
        return res;     
    }
};

class Solution {
public:
    int dpresult(int index, vector<int>& dp_array, vector<int>& nums){
    
        if(index == nums.size()-1 || index == nums.size()-2){
            return nums[index];
        }
        if(dp_array[index]!=-1){
            return dp_array[index];
        }
        int oneskip =nums[index] + dpresult(index+2, dp_array, nums);
        int doubleskip = INT_MIN;
        
        if(index+3<nums.size()){
            doubleskip = nums[index] + dpresult(index+3, dp_array, nums);
        }
                
        dp_array[index] = max(oneskip, doubleskip);

        return dp_array[index]; 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_array(n, -1);

        int startzero = dpresult(0, dp_array, nums);

        int doublezero =INT_MIN;
        if(n>1){
            doublezero = dpresult(1, dp_array, nums);

        }
        
        return max(startzero, doublezero);        
    }
};

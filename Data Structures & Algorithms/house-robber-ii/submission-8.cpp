class Solution {
public:
    int dpresult(int index, vector<int>& dp_array, vector<int>& nums, int finishing_point){
        if(index>finishing_point){
            return 0;
        }

        if(dp_array[index]!=-1) return dp_array[index];

        int robCurrent = nums[index] + dpresult(index+2, dp_array, nums, finishing_point);
        int skipnow = dpresult(index+1, dp_array, nums,finishing_point);

        dp_array[index] = max(robCurrent, skipnow);
        return dp_array[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int startzero = dpresult(0 , dp1, nums, n-2);

        int startone = dpresult(1, dp2, nums, n-1);

        return max(startzero, startone);               
    }
};

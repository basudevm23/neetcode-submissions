class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp(nums.size());
        int i = 0;
        for(auto num: nums){
            if(num!=val){
                temp[i] = num;
                i++;
            }
        }

        nums = temp;
        return i; 
    }
};
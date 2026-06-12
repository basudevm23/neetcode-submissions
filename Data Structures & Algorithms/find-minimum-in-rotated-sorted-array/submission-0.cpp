class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        
        int low=0;
        int right=n-1;
        while(low<right){
            int mid=low+(right-low)/2;

            if(nums[mid]>nums[right]){
                low=mid+1;
            }
            else right=mid;
        }
        return nums[low];
    }
};

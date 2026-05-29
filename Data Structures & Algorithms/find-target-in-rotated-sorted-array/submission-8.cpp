class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left= 0;
        int right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            // left sorted array 3 5 6 8 9 1 2
            if(nums[mid]>=nums[left]){
                if(nums[mid]>target && target>=nums[left]){
                    right=  mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            // right sorted 8 9 1 2 3 5 6
            
            else{
                if(nums[mid]<target && target<=nums[right]){
                    left =  mid+1;
                }
                else right = mid-1;
            }
        }
        return -1;
                
        
    }
};

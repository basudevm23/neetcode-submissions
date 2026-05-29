#include <cmath>
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        if(nums[n-1]>=nums[0]){
            return nums[0];
        }
        while(left<=right){
            int mid = left + (right-left)/2;
            // left sorted array
            if(nums[mid]<nums[(mid+1)%n]&&nums[mid]<nums[(mid-1+n)%n]){
                return nums[mid];
            }
            if(nums[mid]>=nums[right]){
                left = mid+1;                
            }
            // right 
            else{
                right = mid-1;
            }
        }
        return -1;          
    }
};

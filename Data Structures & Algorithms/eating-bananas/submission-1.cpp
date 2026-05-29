#include <cmath>
class Solution {
public:
    int returnh(vector<int>& nums, int rate){
        long long ans =0 ;
        for(int i=0; i<nums.size(); i++){
            ans += (nums[i]+rate-1)/rate;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxp = INT_MIN;
        int n = piles.size();
        for(int i=0; i<n;i++){
            maxp = max(maxp, piles[i]);
        }
        // 1 2 3 4
        int left = 1;
        int right = maxp;
        int hf = maxp;
        while(left<=right){
            int mid  = left + (right-left)/2;
            long long timetaken = returnh(piles, mid);
            if(timetaken<=h){
                hf = mid;
                right= mid-1;
                
            }
            else{
                left = mid+1;
            }
            
        }  
        return hf;
    }
};

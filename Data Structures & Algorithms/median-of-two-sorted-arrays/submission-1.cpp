class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        // binary search on the smaller array
        vector<int> a = nums1;
        vector<int> b = nums2;
        if(nums1.size()>nums2.size()){
            b = nums1;
            a = nums2;
        }
        int left = -1;
        int right = a.size();
        
        int aleft=0;
        int bleft=0;
        int bright=0;
        int aright=0;

        while(left<=right){
            
            int mid = (left + right)/2;

            int half = (total+1)/2 -mid; 
            // (13+1)/2 - 2 = 

            if(mid>0){
                aleft = a[mid-1];
            }
            else{
                aleft = INT_MIN;
            }

            if(half>0){
                bleft = b[half-1];
            }
            else{
                bleft = INT_MIN;
            }

            if(mid<a.size()){
                aright = a[mid];
            }
            else{
                aright = INT_MAX;
            }

            if(half<b.size()){
                bright = b[half];
            }
            else{
                bright = INT_MAX;
            }

            if(aleft <= bright && bleft <= aright){
                if(total%2){
                    return max(aleft, bleft);
                }
                return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }
            else if(aleft > bright){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
            
        }
        return -1;
    }
};

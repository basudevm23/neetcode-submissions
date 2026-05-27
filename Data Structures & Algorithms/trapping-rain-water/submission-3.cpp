class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int n = height.size();
        int left= 0;
        int right = n-1;
        int area_water = 0;
        int leftmax = height[0];
        int rightmax = height[n-1];
        
        while(left<right){
            if(leftmax<rightmax){
                left++;
                leftmax = max(leftmax, height[left]);
                area_water += leftmax - height[left];
            }
            else{
                right--;
                rightmax = max(rightmax, height[right]);
                area_water += rightmax - height[right];
            }
        }
        return area_water;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right =heights.size()-1;
        int maxi =min(heights[left], heights[right]);

        while(left<right){
            int area = (right - left)*min(heights[left], heights[right]);
            maxi = max(maxi, area);
            if(heights[left]<heights[right]){
                left++;
                
            }
            else{
                right--;
            }

        }
        return maxi;
        
    }
};

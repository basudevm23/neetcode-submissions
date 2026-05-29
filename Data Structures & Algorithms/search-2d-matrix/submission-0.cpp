class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // increasing 
        // applying on the rows
        int row = matrix.size();
        int column = matrix[0].size();
        int left = 0;
        int right = row-1;
        int index=-1;
        
        while(left<=right){
            int mid= left + (right-left)/2;
            if(matrix[mid][0]>target){
                right = mid-1;
            }
            else if(target>= matrix[mid][0] && target<= matrix[mid][column-1]){
                index = mid;
                break;
            }
            else if(matrix[mid][column-1]<target){
                left = mid+1;
            }
        } 
        if(index==-1) return false;
        int leftnew = 0;
        int rightnew = column-1;
        while(leftnew<=rightnew){
            int midnew = leftnew+ (rightnew-leftnew)/2;
            if(matrix[index][midnew]<target){
                leftnew = midnew + 1;
            }
            else if(matrix[index][midnew]>target){
                rightnew = midnew-1;
            }
            else if(matrix[index][midnew]==target){
                return true;
            }
        }
        return false;   
    }
};

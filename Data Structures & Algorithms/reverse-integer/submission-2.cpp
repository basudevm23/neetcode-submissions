class Solution {
public:
    int reverse(int x) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int res = 0;
        while(x!=0){
            int rem = x%10;
            x = x/10;
            if(res>maxi/10 || (res==mini/10 && rem>maxi%10)){
                return 0;

            }
            if(res<mini/10 || (res==mini/10 && rem<mini%10)){
                return 0;
                
            }
            res = res*10 + rem;

        }
        return res;
    }
};

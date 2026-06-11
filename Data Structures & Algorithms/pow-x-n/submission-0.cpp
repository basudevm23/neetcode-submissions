class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1.00000;
        if(n==0) return 1.00000;
        else if(n>0){
            double res = 1.00000;
            while(n){
                res = res*x;
                n--;
            }
            return res;
        }
        else{
            double res = 1.00000;
            while(n<0){
                res = res/x;
                n++;
            }
            return res;
        }
        return -1;
    }
};

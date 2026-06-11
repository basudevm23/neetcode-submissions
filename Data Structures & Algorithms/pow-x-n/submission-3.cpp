class Solution {
public:
    double helper(double x, int n){
            if(x==0) return 0;
            if(n==0) return 1;

            double res = helper(x, n/2);
            res = res*res;
            if(n%2) return res*x;
            return res;
        }
    double myPow(double x, int n) {
        double ans = helper(x, abs(n));
        if(n<0) return 1/ans;
        return ans;
    }
};

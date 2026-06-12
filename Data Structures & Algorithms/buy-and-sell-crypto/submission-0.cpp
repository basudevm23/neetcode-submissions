class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=l+1;
        int n=prices.size();
        int profit=0;

        while(r<=n-1){
            if(prices[r]<prices[l]){
                l=r;
            }
            else profit= max(profit, prices[r]-prices[l]);
            r++;
        }
        return profit;
    }
};

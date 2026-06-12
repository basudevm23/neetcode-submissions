class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int buy =0;
        int sell =buy+1;

        while(buy<sell && sell<n){
            if(prices[buy]>prices[sell]){
                buy = sell;
            }           
            maxprofit = max(maxprofit, prices[sell]-prices[buy]);
            sell++;
        }

        return maxprofit;
    }
};

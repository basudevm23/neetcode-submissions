class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> amountarray(amount+1, amount+1);
        amountarray[0] = 0;
        for(int i=1; i<amountarray.size(); i++){
            for(int coin: coins){
                if(i - coin >= 0){
                    amountarray[i] = min(amountarray[i], 1+ amountarray[i-coin]);
                }
            }
        }

        if(amountarray[amount]!=amount+1){
            return amountarray[amount];

        }
        return -1;
    }
};

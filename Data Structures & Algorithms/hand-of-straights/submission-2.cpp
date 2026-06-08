class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // o n for searching 
        
        // 1,2,2,3,3,4,4,5
        vector<int> hash(1001, 0);
        sort(hand.begin(), hand.end());
        
        int n =hand.size();
        for(int i =0; i<n; i++){
            hash[hand[i]] +=1;                                    
        }
        for(int i=0; i<1001; i++){
            if(hash[i]>0){
                int k = 0;
                int m = groupSize;
                while(m){
                    hash[i+k]--;
                    k++;
                    m--;
                }
                i=-1;                
            }
        }
        for(int i=0; i<1001; i++){
            if(hash[i]<0){
                return false;
            }
        }
        return true;
        
    }
};

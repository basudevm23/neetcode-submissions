class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int cnt1=0;
        int cnt2 = 0;
        int cnt3 = 0;
        for(int i=0; i<n; i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]){
                continue;
            }
            if(triplets[i][1]==target[1]){
                cnt2=1;
            }
            if(triplets[i][2]==target[2]){
                cnt3=1;
            }
            if(triplets[i][0] ==target[0]){
                cnt1 = 1;
            }
        }
        return cnt1 + cnt2 + cnt3==3;
    }
};

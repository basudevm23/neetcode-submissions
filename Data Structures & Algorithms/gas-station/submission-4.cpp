class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sumgas= 0;
        int sumcost=0;
        for(int i=0; i<n;i++){
            sumgas += gas[i];
            sumcost += cost[i];
        }
        if(sumcost>sumgas){
            return -1;
        }
        int index=0;
        int total = 0;
        for(int i=0;i<n;i++){
            total = total + (gas[i]-cost[i]);
            if(total<0){
                total = 0;
                index=i+1;
            }
        }
        return index;
    }
};

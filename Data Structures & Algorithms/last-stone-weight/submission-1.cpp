class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i=0;i<stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int maxweight = pq.top();
            pq.pop();
            int secondmaxweight = pq.top();
            pq.pop();
            if(maxweight> secondmaxweight){
                pq.push(maxweight - secondmaxweight);
            }
            else{
                pq.push(0);
            }
        }
        return pq.top();
    }
};

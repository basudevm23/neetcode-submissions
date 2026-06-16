class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hashmap(26, 0);
        for(int i=0; i<tasks.size(); i++){
            hashmap[tasks[i]-'A']++;
        }
        priority_queue<int> pq;

        for(int i=0; i<26; i++){
            if(hashmap[i]!=0){
                pq.push(hashmap[i]);
            }
        }
        queue<pair<int, int>> q;
        int time =0 ;
        while(true){
            if(!pq.empty()){
                int topp = pq.top();
                pq.pop();
                if(topp-1!=0){
                    q.push({topp-1, time+n+1});
                }     
            }          
            time++;
            if(pq.empty()&&q.empty()) return time;
                        
            if(q.front().second==time){
                if((q.front().first)){
                    pq.push(q.front().first);
                }              
                q.pop();
            }
        }
        return time;
    }
};

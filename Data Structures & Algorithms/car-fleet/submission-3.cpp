class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int, int>> decsorted(position.size());
        for(int i=0; i<position.size(); i++){
            decsorted[i] = {position[i], speed[i]};
        }
        sort(decsorted.begin(), decsorted.end(), greater<pair<int, int>>());
        for(int i=0; i<position.size(); i++){
            int pos = decsorted[i].first;
            int spd = decsorted[i].second;
            double lastcartime = -1;
            if(!st.empty()){
                lastcartime = st.top();
            }
            st.push((1.0*(target - pos))/spd);
            double currtime = st.top();
            if(position.size()>1 && lastcartime >= currtime && lastcartime!=-1){
                st.pop();
            }
        }
        return st.size();
    }
};

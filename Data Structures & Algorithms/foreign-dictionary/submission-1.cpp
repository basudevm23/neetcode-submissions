class Solution {
public:
    vector<int> toposort(vector<vector<int>>& adj, int k){
        queue<int>q;
        vector<int> res;
        vector<int> indegree(k,  0);

        for(int i = 0; i<k; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(int it: adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);                    
                }
            }
        }

        return res;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        
        unordered_set<int> st;

        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j< words[i].size(); j++){
                st.insert(words[i][j] - 'a');
            }
        }

        int k  = 26;
        vector<vector<int>> adj(k);


        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int mini = min(s1.length(), s2.length());
            bool check = false;
            for(int ptr = 0; ptr<mini; ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    check = true;
                    break;
                }
            }

            if(check == false && s1.length() > s2.length()){
                return "";
            }
        }

        vector<int> ans = toposort(adj, k);
        string res;
        if(ans.size()!=26){
            return res;
        }



        for(int i = 0; i < ans.size(); i++){
            if(st.count(ans[i])>0){
                res += char(ans[i] + 'a');
            }
        }

        return res;
    }
};

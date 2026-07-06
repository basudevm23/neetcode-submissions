class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //  we need kahn's algo

        queue<int> q;
        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            int crs = prerequisites[i][0];
            int pre = prerequisites[i][1];

            indegree[crs]++;
            adj[pre].push_back(crs);
        }
        vector<int> res;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int i=0; i<adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }

        if(res.size()!=numCourses){
            return {};
        }
        return res;        
    }
};

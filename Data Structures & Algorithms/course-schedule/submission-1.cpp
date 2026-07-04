class Solution {
public:
    bool dfs(int course, vector<int>& vis, vector<vector<int>>& adjlist){
        if(vis[course]==1) return false;
        if(adjlist[course].size()==0){
            return true;
        }
        vis[course]=1;
        for(auto i: adjlist[course]){
            if(dfs(i, vis, adjlist)==false) return false;
        }
        vis[course]=0;
        adjlist[course].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adjlist(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            int crs = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adjlist[crs].push_back(prereq);
        }

        for(int i=0; i<numCourses; i++){
            if(dfs(i, vis, adjlist)==false) return false;
        }
        return true;
    }
};

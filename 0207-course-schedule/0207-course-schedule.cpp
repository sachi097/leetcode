class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        
        for(auto vec: prerequisites){
            int v = vec[0];
            int u = vec[1];
            
            indegree[v]++;

            adj[u].push_back(v);
        }

        queue<int> q;
        int count = 0;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count == numCourses){
            return true;
        }

        return false;
    }
};
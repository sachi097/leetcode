class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        vector<int> result;
        
        for(auto vec: prerequisites){
            int u = vec[1];
            int v = vec[0];
            
            indegree[v]++;

            adj[u].push_back(v);
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                result.push_back(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    result.push_back(v);
                }
            }
        }
        
        if(result.size() == numCourses){
            return result;
        }

        return {};
    }
};
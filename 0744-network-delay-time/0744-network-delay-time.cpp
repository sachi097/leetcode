class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
        }
        
        set<pair<int, int>> st;
        vector<int> result(n+1, INT_MAX);
        
        result[k] = 0;
		st.insert({0, k});

		while(!st.empty()) {

		    auto top  = *st.begin();
		    int u = top.second;
            int d = top.first;
		    st.erase(top);

		    for(auto &edge : adj[u]) {

    			int v = edge.first;
    			int w = edge.second;
    
    			if(d + w < result[v]) {
                    
                    if(result[v] != INT_MAX){
                        st.erase({result[v], v});
                    }

    			    result[v] = d + w;
    			    st.insert({d+w, v});
    
    			}

		    }

		}

        int max = *max_element(result.begin() + 1, result.end());

        return max == INT_MAX ? -1: max;
    }
};
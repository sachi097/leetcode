class Solution {
public:
    void dfs(int currentRoom, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[currentRoom]=1;
        for(auto i=0; i<rooms[currentRoom].size(); i++){
            if(!visited[rooms[currentRoom][i]]){
                dfs(rooms[currentRoom][i], rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n, 0);
        dfs(0, rooms, visited);
        for(auto i=0; i<n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
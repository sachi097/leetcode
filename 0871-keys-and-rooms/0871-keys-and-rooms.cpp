class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        queue<int> keysQ;
        keysQ.push(0);
        while(!keysQ.empty()){
            int nextRoom = keysQ.front();
            keysQ.pop();
            if(!visited[nextRoom]){
                visited[nextRoom] = 1;
                for(auto newKey: rooms[nextRoom]){
                    if(!visited[newKey]){
                        keysQ.push(newKey);
                    }
                }
            }
        }
        for(auto visitedRoom: visited){
            if(!visitedRoom) return false;
        }
        return true;
    }
};
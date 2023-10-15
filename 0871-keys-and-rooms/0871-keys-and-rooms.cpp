class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        visited[0] = 1;
        queue<int> keysQ;
         for(auto key: rooms[0]){
            keysQ.push(key);
        }
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
        bool visitedAll = true;
        for(auto visitedRoom: visited){
            visitedAll = visitedAll && visitedRoom;
        }
        return visitedAll;
    }
};
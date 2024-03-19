class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> map;
        vector<pair<int, char>> temp;
        for(auto el: tasks){
            map[el]++;
        }
        for(auto el: map){
            maxHeap.push({el.second, el.first});
            map[el.first] = 0;
        }
        int counter = 0;
        while(!maxHeap.empty()){
            counter++;
            temp.clear();
            while(!maxHeap.empty() && map[maxHeap.top().second] >= counter){
                temp.push_back(maxHeap.top());
                maxHeap.pop();
            }
            if(!maxHeap.empty()){
                auto currentTask = maxHeap.top();
                maxHeap.pop();
                char taskId = currentTask.second;
                if(counter > map[taskId]){
                    currentTask.first--;
                    map[taskId] = counter + n;
                }
                if(currentTask.first){
                    maxHeap.push(currentTask);
                }
            }
            for(auto el: temp){
                maxHeap.push(el);
            }
        }
        return counter;
    }
};
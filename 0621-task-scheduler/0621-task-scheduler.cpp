class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        unordered_map<char, int> map;
        queue<pair<int, int>> q;
        for(auto el: tasks){
            map[el]++;
        }
        for(auto el: map){
            maxHeap.push(el.second);
        }
        int counter = 0;
        while(!maxHeap.empty() || !q.empty()){
            counter++;
            if(!maxHeap.empty()){
                int currentTask = maxHeap.top();
                maxHeap.pop();
                currentTask--;
                if(currentTask){
                    q.push({currentTask, counter + n});
                }
            }
            if(!q.empty() && q.front().second == counter){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return counter;
    }
};
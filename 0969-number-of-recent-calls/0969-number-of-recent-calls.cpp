class RecentCounter {
public:
    queue<int> requests;
    int upperBound, lowerBound;
    RecentCounter() {
        upperBound = 0;
        lowerBound = 0;
        while(!requests.empty())
            requests.pop();
    }
    
    int ping(int t) {
        int upperBound = t;
        int lowerBound = t - 3000;
        requests.push(t);
        while(requests.front() < lowerBound)
            requests.pop();
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
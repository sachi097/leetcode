class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> infSet;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            infSet.insert(i);
             pq.push(i);
        }       
    }
    
    int popSmallest() {
        int small = pq.top();
        pq.pop();
        infSet.erase(small);
        return small;     
    }
    
    void addBack(int num) {
        if(infSet.find(num) == infSet.end()){
            infSet.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
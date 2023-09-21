class MinStack {
public:
    int minEle;
    stack<int> st;
    MinStack() {
        minEle = INT_MAX;
    }
    
    void push(int val) {
        st.push(minEle);
        st.push(val);
        minEle = min(minEle, val);
    }
    
    void pop() {
        st.pop();
        minEle = st.top(); 
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
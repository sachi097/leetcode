class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // BFS - explore the possible states

        if(x+y < target) return false;
        unordered_set<int>st;
        st.insert(0);

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int a=q.front(); q.pop();
            if(a==target)  return true;

            int val=a+x;
            if(val>=0 && val<=x+y && st.find(val)==st.end()){
                st.insert(val);
                q.push(val);
            }
            val=a-x;
            if(val>=0 && val<=x+y && st.find(val)==st.end()){
                st.insert(val);
                q.push(val);
            }
            val=a+y;
            if(val>=0 && val<=x+y && st.find(val)==st.end()){
                st.insert(val);
                q.push(val);
            }

            val=a-y;
            if(val>=0 && val<=x+y && st.find(val)==st.end()){
                st.insert(val);
                q.push(val);
            }
        }
        return false;
    }
};
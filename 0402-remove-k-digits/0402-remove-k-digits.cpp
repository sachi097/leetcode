class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() < k) return "0";
        stack<char> st;
        for(auto c: num){
            while(!st.empty() && st.top() > c && k){
                k--;
                st.pop();
            }
            if(!st.empty() || c != '0'){
                st.push(c);
            }
        }
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        int n = num.size();
        while(!st.empty()){
            num[n-1] = st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
    }
};
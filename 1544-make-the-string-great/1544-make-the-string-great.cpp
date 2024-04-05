class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans;
        for(auto i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z' && !st.empty() && st.top() >= 'a' && st.top() <= 'z' && !st.empty() && st.top() == tolower(s[i])){
                st.pop();
            }
            else if(s[i] >= 'a' && s[i] <= 'z' && !st.empty() && st.top() >= 'A' && st.top() <= 'Z' && tolower(st.top()) == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);   
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
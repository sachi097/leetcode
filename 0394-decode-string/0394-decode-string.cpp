class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string tempString, tempRepeat, finalString;
        int repeat = 0;
        for(auto i=0; i < s.size(); i++){
            if(s[i] == ']'){
                tempString = "", finalString = "", tempRepeat = "";
                while(!st.empty() && st.top() != "["){
                    tempString = st.top() + tempString;
                    st.pop();
                }
                st.pop();
                while(!st.empty() && st.top() >= "0" && st.top() <= "9"){
                    tempRepeat = st.top() + tempRepeat;
                    st.pop();
                }
                repeat = stoi(tempRepeat);
                for(auto j=0; j<repeat; j++){
                    finalString += tempString;
                }
                st.push(finalString);
            }
            else{
                st.push(string(1,s[i]));
            }
        }
        finalString = "";
        while(!st.empty()){
            finalString = st.top() + finalString;
            st.pop();
        }
        return finalString;
    }
};
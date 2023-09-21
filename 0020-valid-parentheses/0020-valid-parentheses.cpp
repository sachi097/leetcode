class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
        st.push('\0');
      for(int i=0;i<s.length();i++)
      {
          if(s[i]=='(' || s[i]=='{' || s[i]=='[')
          {
            st.push(s[i]);
          }
          else
          {
            switch(s[i])
            {
              case '}': if(st.top()!='{')
                          return false;
                        else
                          st.pop();
                        break;
              case ']': if(st.top()!='[')
                          return false;
                        else
                          st.pop();
                        break;
              case ')': if(st.top()!='(')
                          return false;
                        else
                          st.pop();  
              }
          }
        }
        if(st.top()=='\0')
          return true;
        else
          return false;
    } 
};
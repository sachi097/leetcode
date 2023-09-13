class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        istringstream iss(s);
        string word;
        while(iss >> word) {
            result = word + " " + result;
        }
        return result.substr(0, result.size() - 1);
        // another approach
        // int n=s.size(),i=0;
        // string ans="";
        // while(i<n)
        // {
        //     string tm="" ;
        //    while( s[i]==' '&& i<n)
        //       i++;
        //    while( s[i]!=' '&& i<n)
        //    {
        //   tm+=s[i];
        //       i++;
        //    }
        //    if(tm.size()>0){
        //        if(ans.size()==0)
        //        ans=tm;
        //        else
        //        ans= tm+" "+ans;
        //    }
        // }
        // return ans;
    }
};
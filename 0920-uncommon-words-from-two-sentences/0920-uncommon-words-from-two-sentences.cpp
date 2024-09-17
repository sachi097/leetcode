class Solution {
public:
    vector<string> uncommonFromSentences(string w1, string w2) {
        unordered_map<string,int>m;
        vector<string> ans;
        int j=0;
        for(int i=0;i<=w1.size();i++){
            if(w1[i]==' ' || i==w1.size()){
                string x="";
                x.append(w1.substr(j,i-j));
                m[x]++;
                j=i+1;
            }
        }
        j=0;
        for(int i=0;i<=w2.size();i++){
            if(w2[i]==' ' || i==w2.size()){
                string x="";
                x.append(w2.substr(j,i-j));
                m[x]++;
                j=i+1;
            }
        }
        for(auto it:m)
        {
          if(it.second==1)
          ans.push_back(it.first);
        }
        return ans;
    }
};
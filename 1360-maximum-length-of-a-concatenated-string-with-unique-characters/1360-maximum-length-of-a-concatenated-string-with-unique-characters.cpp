class Solution {
public:
    unordered_map<string, int> mp;

    int solve(int i, vector<string> &words, string ansString, unordered_set<char> st){
        int n = words.size();
        if(i == n){
            return ansString.size();
        }

        if(mp.find(ansString) != mp.end()){
            return mp[ansString];
        }

        int excludeStringSize = solve(i+1, words, ansString, st);

        int includeStringSize = words[i].size();
        int currentLength = 0;
        for(auto &ch: words[i]){
            if(st.find(ch) != st.end()){
                int j = 0;
                while(j<currentLength){
                    st.erase(words[i][j]);
                    ansString.pop_back();
                    j++;
                }
                includeStringSize = 0;
                break;
            }
            st.insert(ch);
            ansString += ch;
            currentLength++;
        }

        includeStringSize = solve(i+1, words, ansString, st);

        return mp[ansString] = max(excludeStringSize, includeStringSize);

    }

    int maxLength(vector<string>& arr) {
        mp.clear();
        unordered_set<char> st;
        return solve(0, arr, "", st);
    }
};
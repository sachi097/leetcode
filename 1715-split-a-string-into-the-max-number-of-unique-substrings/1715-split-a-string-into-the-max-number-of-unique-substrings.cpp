class Solution {
public:
    void solve(string& s, int i, unordered_set<string>& st, int currCount, int& maxCount) {
        if(currCount + (s.length() - i) <= maxCount) { //Pruning for slight improvement
            return;
        }

        if(i == s.length()) {
            maxCount = max(maxCount, currCount);
        }

        for(int j = i; j < s.length(); j++) {
            string sub = s.substr(i, j-i+1);
            if(st.find(sub) == st.end()) {
                // Backtracking Khandani Template
                st.insert(sub); //Do
                solve(s, j+1, st, currCount+1, maxCount); // Explore
                st.erase(sub); // Undo
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount  = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};
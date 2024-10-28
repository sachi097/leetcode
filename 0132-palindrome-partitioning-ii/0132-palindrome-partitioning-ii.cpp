class Solution {
public:

    int n;
    vector<vector<int>> dp;
    
    void fillPalindromeTable(string s){
        for(int L=1; L<=n; L++){
            for(int i=0; i+L-1 < n; i++){
                int j = i+L-1;
                if(i==j){
                    dp[i][j] = 1;
                }
                else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
                else if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = 1;
                }
            }
        }
    }

    int minCut(string s) {
        n = s.size();

        if(n == 1){
            return 0;
        }

        dp.assign(n, vector<int>(n, 0));

        fillPalindromeTable(s);

        vector<int> p(n);
        
        for(int i = 0; i<n; i++) {
            if(dp[0][i] == true) // string from s[0..i] is palindrome
                p[i] = 0; // so no cut required
            else {
                p[i] = INT_MAX;
                for(int k = 0; k<i; k++) {
                    if(dp[k+1][i] == true && 1 + p[k] < p[i])
                        p[i] = 1 + p[k];
                }   
            }
        }

        return p[n-1];
    }
};
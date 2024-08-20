using namespace std;
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int alice(int isBob, int i, int m, vector<int>& piles, int n){
        if (i == n) return 0;
        if (dp[isBob][i][m]!=-1) return dp[isBob][i][m];
        int stones =( isBob == 0 )? 0: INT_MAX;
        int sum = 0;
        for (int x = 1; x <= min(2 * m, n - i); x++) {
            sum += piles[i + x - 1];
            if (isBob) 
                stones = min(stones, alice(0, i + x, max(m, x), piles, n));
            else 
                stones = max(stones, 
                sum + alice(1, i + x, max(m, x), piles,n ));                       
        }
        dp[isBob][i][m]=stones;
        return stones;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(2,vector(n+1, vector<int>(n+1, -1) ));
        return alice(0, 0, 1,  piles, n );
    }
};
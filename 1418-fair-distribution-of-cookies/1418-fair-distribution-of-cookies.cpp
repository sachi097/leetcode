class Solution {
public:
    int unfair = INT_MAX;
    void solve(int idx, vector<int> &cookies, int &k, vector<int> &dist){
        if(idx == cookies.size()){
            int maxEle = *max_element(dist.begin(), dist.end());
            unfair = min(unfair, maxEle);
            return;
        }

        int currCookie = cookies[idx];
        for(auto i=0; i<k; i++){
            dist[i] += currCookie; // do
            solve(idx+1, cookies, k, dist); // explore
            dist[i] -= currCookie; // undo
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k, 0);
        solve(0, cookies, k, dist);
        return unfair;
    }
};
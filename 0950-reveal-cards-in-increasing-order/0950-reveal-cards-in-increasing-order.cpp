class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size(), index;
        queue<int> q;
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            q.push(i);
        }
        for(auto i=0; i<n;i++){
            index = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            ans[index] = deck[i];
        }
        
        return ans;
    }
};
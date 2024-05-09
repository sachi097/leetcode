class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> pq;
        for(auto el: happiness){
            pq.push(el);
        }
        long long count = 0, ans = 0, top;
        while(k > 0){
            top = pq.top();
            ans += top > count ? (top - count) : 0;
            pq.pop();
            count++;
            k--;
        }
        return ans;
    }
};
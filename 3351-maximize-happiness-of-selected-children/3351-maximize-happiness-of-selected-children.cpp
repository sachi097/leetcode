class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long count = 0, ans = 0, top;
        // priority_queue<long long> pq;
        // for(auto el: happiness){
        //     pq.push(el);
        // }
        // while(k > 0){
        //     top = pq.top();
        //     ans += top > count ? (top - count) : 0;
        //     pq.pop();
        //     count++;
        //     k--;
        // }
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(auto i=0; i<k; i++, count++){
            top = happiness[i];
            ans += top > count ? (top - count) : 0;
        }
        return ans;
    }
};
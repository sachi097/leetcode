class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<int, vector<int>, greater<int>> minSumHeap;

        for(int i=0; i<nums1.size(); i++){
            minHeap.push({nums1[i], i});
        }

        vector<long long> ans(nums1.size());
        long long sum = 0;

        int prev = -1;
        long long prevSum = 0;

        while(!minHeap.empty()){
            pair<int, int> topEle = minHeap.top();
            minHeap.pop();

            if(prev == topEle.first){
                ans[topEle.second] = prevSum;
            }
            else{
                ans[topEle.second] = sum;
                prevSum = sum;
            }

            prev = topEle.first;
            
            sum += nums2[topEle.second];
            minSumHeap.push(nums2[topEle.second]);

            if(minSumHeap.size() > k){
                sum -= minSumHeap.top();
                minSumHeap.pop();
            }

        }

        return ans;
    }
};
class Solution {
public:
    int quickPartition(vector<int>& nums, int L, int R) {
        
        int P = nums[L];
        int i = L+1; //0
        int j = R; //0
        
        while(i <= j) {
            
            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            
            if(nums[i] >= P) {
                i++;
            }
            
            if(nums[j] <= P) {
                j--;
            }
            
        }
        
        swap(nums[L], nums[j]);
        return j; //P is at jth index
    }

    int quickSelect(vector<int> &nums, int left, int right, int k){
        int p = quickPartition(nums, left, right);
        if(p == k){
            return nums[p];
        }
        else if(p < k){
            return quickSelect(nums, p+1, right, k);
        }
        return quickSelect(nums, left, p-1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        // quick select
        return quickSelect(nums, 0, nums.size()-1, k-1);
        
        // using priority queue
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int i=0; i<k; i++){
        //     pq.push(nums[i]);
        // }
        // for(int i=k; i<nums.size();i++){
        //     if(pq.top() < nums[i]){
        //         pq.pop();
        //         pq.push(nums[i]);
        //     }
        // }
        // return pq.top();
    }
};
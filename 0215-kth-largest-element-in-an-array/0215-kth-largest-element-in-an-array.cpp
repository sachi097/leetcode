class Solution {
public:
    int findPartition(vector<int>&nums, int start, int end) {
        int i = start - 1;
        int pivot = nums[end];
        for(int j = start; j < end; ++j) {
            if(nums[j] <= pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        i = i+1;
        swap(nums[i], nums[end]);
        return i;
    }
    int quickSelect(vector<int>& nums, int n_k, int start, int end) {
        int pindex = findPartition(nums, start, end);
        if (pindex == n_k) return pindex;
        if (pindex < n_k) {
            // skip identical value : Last testcase leading to TLE
            pindex += 1;
            while(pindex < n_k && nums[pindex] == nums[pindex-1]) pindex++; 

            return randPartition(nums, n_k, pindex, end);
        } else {
            // skip identical value : Last testcase leading to TLE
            pindex -= 1;
            while(pindex > n_k && nums[pindex] == nums[pindex+1]) pindex--; 

            return randPartition(nums, n_k, start, pindex);
        }
    }
    int randPartition(vector<int>& nums, int n_k, int start, int end) {
        int randIndex = start + rand() % (end-start+1);
        swap(nums[end], nums[randIndex]);
        return quickSelect(nums, n_k, start, end);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int pindex = randPartition(nums, n-k, 0, n-1);
        return nums[pindex];

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
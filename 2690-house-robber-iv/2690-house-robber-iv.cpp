class Solution {
public:

    bool find(int mid,vector<int> &nums, int k){
        int house = 0;
        for(auto i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                i++;
                house++;
                if(house >= k){
                    return true;
                }
            }
        }
        return false ;
    }

    int minCapability(vector<int>& nums, int k) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int ans = h;
        while(l<=h){
            int mid = (l + h) / 2;
            if(find(mid, nums, k)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
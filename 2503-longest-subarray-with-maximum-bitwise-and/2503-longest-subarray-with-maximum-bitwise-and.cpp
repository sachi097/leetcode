class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=0,maxi=0,n=nums.size(),i=0;
        while(i<n){
            int j=i;
            while(j<n && nums[i]==nums[j]) j++;
            if(nums[i]>maxi){
                len=j-i;
                maxi=nums[i];
            }
            else if(nums[i]==maxi){
                len=max(len,j-i);
            }
            i=j;
        }
        return len;
    }
};
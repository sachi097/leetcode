class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;       //if size of array is less than 3 we can't make triplate
        //find low, mid such that it is less than large.
        //current number is low if it is < current low
        //current number is mid if it is in between current low and current mid
        int low=INT_MAX, mid=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mid) return true;
            else if(nums[i]<low) low=nums[i];
            else if(nums[i]> low and nums[i]<mid) mid=nums[i];
        }
        return false;
    }
};

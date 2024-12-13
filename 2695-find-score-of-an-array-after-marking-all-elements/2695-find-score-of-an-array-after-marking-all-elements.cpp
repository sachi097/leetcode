class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n=nums.size();
        long long sum=0;
        for(int l, r=0; r<n; r+=2){// step 2, the next 1 should be skipped
            l=r;// position for a local maximum

            while(r+1<n && nums[r]>nums[r+1])
                r++;// Find pos for a local minimum

            for(int i=r; i>=l; i-=2)
                sum+=nums[i];
        }
        return sum;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, leftMax = INT_MIN, rightMax = INT_MIN, ans = 0;
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            ans += leftMax < rightMax ? leftMax - height[left++] : rightMax - height[right--];
        }
        return ans;
    }
};
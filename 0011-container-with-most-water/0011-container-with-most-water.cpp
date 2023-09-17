class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = INT_MIN, left = 0, right = height.size() - 1;
        while(left<right){
            maxarea = max(maxarea, (min(height[left], height[right]) * (right - left)));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};
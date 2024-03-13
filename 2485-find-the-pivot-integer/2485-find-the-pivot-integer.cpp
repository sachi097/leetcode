class Solution {
public:
    int getSum(int n){
        return (n * (n+1)) / 2;
    }
    int pivotInteger(int n) {
        int low = 1, high = n, mid, leftSum, rightSum, nSum = getSum(n);
        while(low <= high){
            mid = low + (high - low) / 2;
            leftSum = getSum(mid);
            rightSum = nSum - leftSum + mid;
            if(leftSum == rightSum){
                return mid;
            }
            if(leftSum > rightSum){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};

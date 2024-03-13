class Solution {
public:
    int getSum(int n){
        return (n * (n+1)) / 2;
    }
    int pivotInteger(int n) {
        int low = 1, high = n, mid, leftSum, rightSum;
        while(low <= high){
            mid = low + (high - low) / 2;
            cout<<mid<<endl;
            leftSum = getSum(mid);
            rightSum = getSum(n) - leftSum + mid;
            cout<<low<<" "<<leftSum<<" "<<high<<" "<<rightSum<<endl;
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
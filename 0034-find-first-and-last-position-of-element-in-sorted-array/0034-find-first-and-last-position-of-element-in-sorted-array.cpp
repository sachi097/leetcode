class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1, mid;
        vector<int> result(2, -1);
        while(low<=high){
            mid = low + (high - low) / 2;
            if(arr[mid] == x){
                result[0] = mid;
                high = mid - 1;
            }
            else if(arr[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        low = 0, high = arr.size() - 1;
        while(low<=high){
            mid = low + (high - low) / 2;
            if(arr[mid] == x ){
                result[1] = mid;
                low = mid + 1;
            }
            else if(arr[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return result;
    }
};
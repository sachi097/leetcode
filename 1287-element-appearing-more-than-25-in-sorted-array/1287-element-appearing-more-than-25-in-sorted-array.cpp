class Solution {
public:
    
    int firstOccurance(vector<int>& arr, int key){
        int low = 0, high = arr.size() - 1, mid, first;
        while(low<=high){
            mid = low + (high - low) / 2;
            if(arr[mid] == key){
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < key){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }
    
    int lastOccurance(vector<int>& arr, int key){
        int low = 0, high = arr.size() - 1, mid, last;
        while(low<=high){
            mid = low + (high - low) / 2;
            if(arr[mid] == key){
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] < key){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }
    
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n / 4;
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        for (int candidate : candidates) {
            int first = firstOccurance(arr, candidate);
            int last = lastOccurance(arr, candidate);
            if(last - first + 1 > target)
                return candidate;
        }
        return -1;
    }
};
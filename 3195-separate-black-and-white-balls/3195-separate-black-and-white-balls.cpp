class Solution {
public:
    long long minimumSteps(string s) {
        // quick partition
        long long swaps = 0;
        int n = s.size(), j = 0;
        char pivot = '1';
        for(auto i=0; i<n; i++){
            if(s[i] != pivot){
                if(i != j){
                    swaps += i - j;
                }
                //swap(s[i], s[j]);
                j++;
            }
        }
        return swaps;
    }
};
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int l = m-1, r = n-1, k = m+n-1;
        while(l >= 0 && r >= 0){
            if(a[l] >= b[r]){
                a[k--] = a[l--];
            }
            else{
                a[k--] = b[r--];
            }
        }
        while(l>=0){
            a[k--] = a[l--];
        }
        while(r>=0){
            a[k--] = b[r--];
        }
    }
};
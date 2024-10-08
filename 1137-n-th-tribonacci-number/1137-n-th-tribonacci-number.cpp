class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribonacci(n+1, 0);
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        tribonacci[0] = 0;
        tribonacci[1] = 1;
        tribonacci[2] = 1;
        for(auto i=3; i<=n; i++){
            tribonacci[i] = tribonacci[i-1] + tribonacci[i-2] + tribonacci[i-3];
        }
        return tribonacci[n];
    }
};
class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector out(1<<n, 0);
        for(int i{1}, p(1); i<size(out); ++i)
        {
            if(i==2*p) p=i;
            out[i] = p+out[2*p-i-1];                   
        }
        return out;   
    }
};
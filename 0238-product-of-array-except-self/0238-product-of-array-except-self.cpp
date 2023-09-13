class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> finalProd;
        int pref = 1, suff = 1;
        for(auto i=nums.begin(); i != nums.end(); i++){
            finalProd.push_back(pref);
            pref *= *i; 
        }
        int j = n - 1;
        for(auto i=nums.rbegin(); i != nums.rend(); i++){
            finalProd[j--] *= suff;
            suff *= *i;
        }
        return finalProd;
    }
};
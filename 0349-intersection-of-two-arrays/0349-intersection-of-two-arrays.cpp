class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> hashSet, ansSet;
        int i=0, j=0, m = nums1.size(), n = nums2.size();
        for(auto el: nums1){
            hashSet.insert(el);
        }
        for(auto el: nums2){
            if(hashSet.find(el) != hashSet.end()){
                ansSet.insert(el);
            }
        }
        return vector<int>(ansSet.begin(), ansSet.end());
    }
};
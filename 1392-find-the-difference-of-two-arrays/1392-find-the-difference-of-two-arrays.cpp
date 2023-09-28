class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        unordered_set<int> nums1_Set, nums2_Set;
        for(auto i = 0; i < nums1.size(); i++){
            if(nums1_Set.find(nums1[i]) == nums1_Set.end()){
                nums1_Set.insert(nums1[i]);
            }
        }
        for(auto i = 0; i < nums2.size(); i++){
            if(nums2_Set.find(nums2[i]) == nums2_Set.end()){
                nums2_Set.insert(nums2[i]);
            }
        }
        for(auto el: nums1_Set){
            if(nums2_Set.find(el) == nums2_Set.end()){
                result[0].push_back(el);
            }
        }
        for(auto el: nums2_Set){
            if(nums1_Set.find(el) == nums1_Set.end()){
                result[1].push_back(el);
            }
        }
        return result;
    }
};
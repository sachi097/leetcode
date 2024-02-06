class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> ans;
        for(auto str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(str);
        }
        for(auto it: hashMap){
            ans.push_back(it.second);
        }
        return ans;
    }
};
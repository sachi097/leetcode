class Solution {
public:
    int strStr(string haystack, string needle) {
        auto itr = haystack.find(needle);
        if(itr == string::npos){
            return -1;
        }

        return itr;
    }
};
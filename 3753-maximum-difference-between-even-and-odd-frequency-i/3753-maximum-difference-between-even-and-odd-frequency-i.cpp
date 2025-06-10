class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> countMap;
        int maxOdd = 1, minEven = s.size();
        for(auto &ch: s){
            countMap[ch]++;
        }

        int count;
        for(auto ele: countMap){
            count = ele.second;
            if(count % 2 == 0){
                minEven = min(minEven, count);
            }
            else{
                maxOdd = max(maxOdd, count);
            }
        }

        return maxOdd - minEven;
    }
};
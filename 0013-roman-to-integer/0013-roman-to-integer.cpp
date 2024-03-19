class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map;
        map.insert({"I", 1});
        map.insert({"V", 5});
        map.insert({"X", 10});
        map.insert({"L", 50});
        map.insert({"C", 100});
        map.insert({"D", 500});
        map.insert({"M", 1000});
        map.insert({"IV", 4});
        map.insert({"IX", 9});
        map.insert({"XL", 40});
        map.insert({"XC", 90});
        map.insert({"CD", 400});
        map.insert({"CM", 900});
        int number = 0;
        for(auto i=0; i<s.size(); i++){
            string currStr = s.substr(i, 2);
            if(map.find(currStr) == map.end()){
                currStr = s.substr(i, 1);
            }
            else{
                i++;
            }
            number += map[currStr];
        }
        return number;
    }
};
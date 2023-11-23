class Solution {
public:
    unordered_map<char, string> digitMap = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void backTrack(string& digits, int idx, string temp, vector<string>& res)
    {
        if (idx == digits.size())
        {
            res.push_back(temp);
            return;
        }

        string characters = digitMap[digits[idx]];
        for (int i = 0; i < characters.size(); i++)
        {
            temp.push_back(characters[i]);
            backTrack(digits, idx+1, temp, res);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        backTrack(digits, 0, "", res);
        return res;
    }
};
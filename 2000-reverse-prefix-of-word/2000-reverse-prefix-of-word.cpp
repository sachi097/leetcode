class Solution {
public:
    string reversePrefix(string word, char ch) {
        // using iterators
        // auto iter = find(word.begin(), word.end(), ch);
        // if(iter != word.end()){
        //     string tempWord = word.substr(0, ++iter - word.begin());
        //     reverse(tempWord.begin(), tempWord.end());
        //     word.replace(word.begin(), iter, tempWord);
        // }

        // using index
        auto iter = word.find(ch);
        if(iter != string::npos){
            string tempWord = word.substr(0, ++iter);
            reverse(tempWord.begin(), tempWord.end());
            word.replace(0, iter, tempWord);
        }
        return word;
    }
};
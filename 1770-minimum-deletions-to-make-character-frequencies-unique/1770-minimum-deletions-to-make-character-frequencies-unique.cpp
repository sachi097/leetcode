class Solution {
public:
    int minDeletions(string s) {
                vector<int> freq(26, 0);
        for(auto &ch: s){
            freq[ch-'a']++;
        }

        unordered_map<int, int> bucket;
        int deletion = 0;
        for(int i=0; i<26; i++){
            if(freq[i]){
                int bucket_key = freq[i];
                while(bucket[bucket_key] != 0){
                    bucket_key--;
                    deletion++;
                }

                if(bucket_key > 0){
                    bucket[bucket_key] = freq[i];
                }
            }
        }

        return deletion;
    }
};
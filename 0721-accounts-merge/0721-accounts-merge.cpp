class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unionSet(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b){
            return;
        }

        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
        }
        else if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
        }
        else{
            parent[parent_b] = parent_a;
            rank[parent_a]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n, 0);
        rank.resize(n, 1);

        unordered_map<string, int> parentMap;
        unordered_map<int, vector<string>> personMap;

        for(auto i=0; i<n; i++){
            parent[i] = i;
            for(auto j=1; j<accounts[i].size(); j++){
                if(parentMap.find(accounts[i][j]) != parentMap.end()){
                    unionSet(parentMap[accounts[i][j]], i);
                }
                else{
                    parentMap[accounts[i][j]] = i;
                }
            }
        }

        for(auto &parentEle: parentMap){
            personMap[find(parentEle.second)].push_back(parentEle.first);
        }

        vector<vector<string>> ans;
        for(auto &person: personMap){
            sort(person.second.begin(), person.second.end());
            vector<string> temp;
            temp.push_back(accounts[person.first][0]);
            temp.insert(temp.end(), person.second.begin(), person.second.end());
            ans.push_back(temp);
        }

        return ans;
    }
};
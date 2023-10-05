class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        if(n == 1){
            return senate[0] == 'R' ? "Radiant" : "Dire";
        }
        queue<int> rQueue, dQueue;
        for(auto i=0; i<senate.size(); i++){
            senate[i] == 'R'? rQueue.push(i) : dQueue.push(i);
        }
        while(!rQueue.empty() && !dQueue.empty()){
            int rS = rQueue.front(), dS = dQueue.front();
            rQueue.pop();
            dQueue.pop();
            if(rS < dS){
                rQueue.push(rS+n);
            }
            else{
                dQueue.push(dS+n);
            }
        }
        return rQueue.size() > 0 ? "Radiant" : "Dire";
    }
};
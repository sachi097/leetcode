class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0, count = 0;
        while(tickets[k] != 0){
            count = 0;
            for(int i=0; i<tickets.size(); i++){
                if(tickets[i]){
                    count++;
                    tickets[i]--;   
                }
                if(tickets[k] == 0){
                    break;
                }
            }
            time += count;
        }
        return time;
    }
};
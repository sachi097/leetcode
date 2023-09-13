class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 1 && n == 1){
                return false;
            }
            else{
                return true;
            }
        }
        int m = flowerbed.size();
        for(auto i=0; i < m && n > 0; i++){
            if(i == 0 && flowerbed[0] == 0 && flowerbed[1] == 0){
                flowerbed[0] = 1;
                n--;
            }
            if(i == m - 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            if(i != 0 && i != m - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0 ? true : false;
    }
};
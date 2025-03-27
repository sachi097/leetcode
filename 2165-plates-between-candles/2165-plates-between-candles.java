class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length();
        int[] nearestLeftCandle = new int[n];
        int[] nearestRightCandle = new int[n];
        int[] numberOfPlates = new int[n];

        Arrays.fill(nearestLeftCandle, -1);
        Arrays.fill(nearestRightCandle, -1);

        for(int i=0; i<n; i++){
            if(s.charAt(i) == '|'){
                nearestLeftCandle[i] = i;
            }
            else if(i > 0){
                nearestLeftCandle[i] = nearestLeftCandle[i-1]; 
            }

            
            
        }

        for(int i=n-1; i>=0; i--){
            if(s.charAt(i) == '|'){
                nearestRightCandle[i] = i;
            }
            else if(i < n-1){
                nearestRightCandle[i] = nearestRightCandle[i+1]; 
            }
            
            
        }
        
        if(s.charAt(0) == '*'){
            numberOfPlates[0] = 1;
        }

        for(int i=1; i<n; i++){
            if(s.charAt(i) == '*'){
                numberOfPlates[i] = 1 + numberOfPlates[i-1];
            }
            else{
                numberOfPlates[i] = numberOfPlates[i-1];
            }
        }

        int[] ans = new int[queries.length];

        int i = 0;
        for(int[] query: queries){
            int left = query[0];
            int right = query[1];

            int rightIndex = nearestLeftCandle[right];
            int leftIndex = nearestRightCandle[left];

            if(leftIndex < rightIndex && leftIndex != -1 && rightIndex != -1){
                ans[i++] = numberOfPlates[rightIndex] - numberOfPlates[leftIndex];
            }
            else{
                ans[i++] = 0;
            }
            
        }
        
        return ans;
    }
}

/*
2 1
3 2
3 3
4 4
5 5
5 6
6 7
7 8
8 9
9 10
10 11
10 12
11 13
12 14
12 15
12 16
13 17
14 18
14 19
15 20
*/
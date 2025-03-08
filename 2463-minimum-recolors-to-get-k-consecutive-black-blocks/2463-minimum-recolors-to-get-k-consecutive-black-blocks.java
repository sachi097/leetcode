class Solution {
    public int minimumRecolors(String blocks, int k) {
        int i=0, j=0, result = Integer.MAX_VALUE;
        int whiteColors = 0;
        while(j<k){
            if(blocks.charAt(j) == 'W'){
                whiteColors++;
            }
            j++;
        }

        result = Math.min(result, whiteColors);

        while(j<blocks.length()){
            if(blocks.charAt(j) == 'W'){
                whiteColors++;
            }
            if(blocks.charAt(i) == 'W'){
                whiteColors--;
            }
            i++;
            j++;
            result = Math.min(result, whiteColors);
        }

        return result;
    }
}
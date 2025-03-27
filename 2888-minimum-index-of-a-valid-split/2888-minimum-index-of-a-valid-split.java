class Solution {
    public int minimumIndex(List<Integer> nums) {
        int n = nums.size();;
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> leftMap = new HashMap<>();
        map.put(0, 0);

        int dominantEle = 0, count = 0;
        for(int i=0; i<n; i++){
            map.put(nums.get(i), map.getOrDefault(nums.get(i), 0) + 1);

            if(map.get(nums.get(i)) > map.get(dominantEle)){
                dominantEle = nums.get(i);
            }
        }

        for(int i=0; i<n; i++){
            if(nums.get(i) == dominantEle){
                count++;
            }
            if(count * 2 > i+1 && ((map.get(dominantEle) - count) * 2 > (n - i - 1))){
                return i;
            }
        }

        return -1;
    }
}
class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] map = new int[26];
        for(int i=0; i<s.length(); i++){
            map[s.charAt(i) - 'a'] = i;
        }
        List<Integer> ans = new ArrayList<>();
        int i = 0, end = 0, start = 0;
        while(i < s.length()){
            end = Math.max(end, map[s.charAt(i) - 'a']);
            if(i == end){
                ans.add(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return ans;
    }
}
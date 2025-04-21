class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] map = new int[26];
        int n = p.length();
        int left = 0, right = 0, index;

        for(int i=0; i<n; i++){
            index = p.charAt(i) - 'a';
            map[index]++;
        }

        int[] windowCount = new int[26];
        List<Integer> ans = new ArrayList<>();

        while(right < s.length()){
            index = s.charAt(right) - 'a';
            if(map[index] == 0){
                left = right + 1;
                Arrays.fill(windowCount, 0);
            }
            else{
                windowCount[index] += 1;
                if((right - left + 1) == n){
                    String pCount = Arrays.toString(map);
                    String sCount = Arrays.toString(windowCount);
                    if(pCount.equals(sCount)){
                        ans.add(left);
                    }
                    windowCount[s.charAt(left) - 'a']--;
                    left++;
                }
            }

            right++;
        }

        return ans;
    }
}
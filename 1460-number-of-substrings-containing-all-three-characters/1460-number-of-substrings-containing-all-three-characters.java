class Solution {

    public int numberOfSubstrings(String s) {
        int ans = 0;
        int n = s.length();
        int left = 0, right = 0; 

        HashMap<Character, Integer> map = new HashMap<>();

        while(right < n){
            Character ch = s.charAt(right);
            
            map.put(ch, map.getOrDefault(ch, 0) + 1);
            
            if(map.size() == 3){
                ans += (n - right);

                while(map.size() == 3){
                    Character leftCh = s.charAt(left);
                    map.put(leftCh, map.get(leftCh) - 1);
                    if(map.get(leftCh) == 0){
                        map.remove(leftCh);
                    }else{
                        ans += (n - right);
                    }
                    left++;
                }
            }

            right++;
        }

        return ans;
    }
}
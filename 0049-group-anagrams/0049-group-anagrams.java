class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for(String str: strs){
            int[] keyArray = new int[26];
            for(Character ch: str.toCharArray()){
                keyArray[ch - 'a'] += 1;
            }
            String key = Arrays.toString(keyArray);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(str);
        }

        return map.values().stream().collect(Collectors.toList());
    }
}
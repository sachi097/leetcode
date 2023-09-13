class Solution {
    public String mergeAlternately(String word1, String word2) {
       String result = "";
       int i=0, j=0, m = word1.length(), n = word2.length();
       while(i < m && j < n){
           result += word1.charAt(i++);
           result += word2.charAt(j++);
       }
       while(i < m){
           result += word1.charAt(i++);
       }
       while(j < n){
           result += word2.charAt(j++);
       }
       return result;
    }
}
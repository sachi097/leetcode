class Solution {
    public String getBinaryString(int n, StringBuilder currString, HashSet<String> numsSet){
        if(currString.length() >= n){
            if(!numsSet.contains(currString.toString())){
                return currString.toString();
            }
            return "";
        }

        currString.append('0'); //do
        String answer = getBinaryString(n, currString, numsSet); //explore
        int length = currString.length();
        currString.replace(length - 1, length, ""); //undo

        if(answer.equals("")){
            currString.append('1'); //do
            answer = getBinaryString(n, currString, numsSet); //explore
            currString.replace(length - 1, length, ""); //undo
        }

        return answer;
    }

    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        HashSet<String> numsSet = new HashSet<>();
        for(String str: nums){
            numsSet.add(str);
        }
        return getBinaryString(n, new StringBuilder(""), numsSet);
    }
}
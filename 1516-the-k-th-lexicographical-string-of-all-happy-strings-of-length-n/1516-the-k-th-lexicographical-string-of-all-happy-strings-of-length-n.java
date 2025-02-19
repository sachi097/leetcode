class Solution {
    String happyString = "";
    String choices = new String("abc");
    int j = 1;

    public void calculateHappyString(int n, int k, String currentString){
        if(currentString.length() >= n){
            if(j == k){
                happyString = currentString;
            }
            j++;
            return;
        }

        for(int i=0; i<choices.length(); i++){
            if(currentString.length() > 0 && currentString.charAt(currentString.length() - 1) == choices.charAt(i)){
                continue;
            }
            currentString += choices.charAt(i);
            calculateHappyString(n, k, currentString);
            currentString = currentString.substring(0, currentString.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        calculateHappyString(n, k, "");
        return happyString;
    }
}
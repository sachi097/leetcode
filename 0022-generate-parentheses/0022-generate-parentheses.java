class Solution {
    List<String> result = new ArrayList<>();
    public void generateValidParenthesis(int n, int openPara, int closedPara, StringBuilder currentStr){
        if(currentStr.length() >= 2*n){
            result.add(currentStr.toString());
        }

        int length;

        if(openPara < n){
            currentStr.append('(');
            openPara++;
            generateValidParenthesis(n, openPara, closedPara, currentStr);
            length = currentStr.length() - 1;
            currentStr.replace(length, length + 1, "");
            openPara--;
        }

        if(closedPara < openPara){
            currentStr.append(')');
            closedPara++;
            generateValidParenthesis(n, openPara, closedPara, currentStr);
            length = currentStr.length() - 1;
            currentStr.replace(length, length + 1, "");
            closedPara--;
        }
    }

    public List<String> generateParenthesis(int n) {
        generateValidParenthesis(n, 0, 0, new StringBuilder());
        return result;
    }
}
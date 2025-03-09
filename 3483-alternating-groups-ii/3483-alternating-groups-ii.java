class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int result = 0;

        int length = 1; // i = 0 index wala element
        int last = colors[0];

        // 1st Pass
        for (int i = 1; i < n; i++) {
            if (colors[i] == last) {
                length = 1;
                last = colors[i];
                continue;
            }

            length++;

            if (length >= k) {
                result++;
            }

            last = colors[i];
        }

        // T.C : O(n)
        // 2nd Pass
        for (int i = 0; i < k - 1; i++) { // checking starting (k-1) elements
            if (colors[i] == last) {
                length = 1;
                last = colors[i];
                break;
            }

            length++;

            if (length >= k) {
                result++;
            }

            last = colors[i];
        }

        return result;
    }
}
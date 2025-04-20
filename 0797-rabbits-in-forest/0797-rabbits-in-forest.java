class Solution {
    public int numRabbits(final int[] answers) {
        final int[] counts = new int[1001];
        int total = 0;

        for(final int ans : answers)
            counts[ans]++;

        for(int i = 0; i <= 1000; i++) {
            if(counts[i] > 0) {
                final int groupSize = i + 1, groups = (counts[i] + groupSize - 1) / groupSize;

                total += groups * groupSize;
            }
        }

        return total;
    }
}
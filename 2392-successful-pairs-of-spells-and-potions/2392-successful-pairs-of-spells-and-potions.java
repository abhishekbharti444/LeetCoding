class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        Arrays.sort(potions);
        int[] res = new int[n];
        for (int i = 0; i < n; ++i) {
            int target;
            target = (int)success/spells[i];
            if (success % spells[i] != 0) target++;
            int index = Arrays.binarySearch(potions, target);
            if (index == m) {
                res[i] = 0;
                continue;
            }
            if (index < 0) {
                index = -(index + 1);
            }
            res[i] = m - index;
        }
        return res;
    }
}
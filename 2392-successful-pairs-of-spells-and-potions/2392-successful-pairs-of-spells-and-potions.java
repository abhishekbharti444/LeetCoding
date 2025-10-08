class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        Arrays.sort(potions);
        int[] res = new int[n];

        for (int i = 0; i < n; ++i) {
            long target = (success + spells[i] - 1) / spells[i];

            // Custom binary search that handles long target
            int index = lowerBound(potions, target);
            res[i] = m - index;
        }
        return res;
    }

    private int lowerBound(int[] arr, long target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
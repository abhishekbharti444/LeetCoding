/**
 * Approach: Dual Data Structure for O(1) Operations
 *
 * Key Insight: Use HashMap for O(1) lookup and ArrayList for O(1) random access
 * - HashMap: Maps value -> index in array (for fast existence check and removal)
 * - ArrayList: Stores actual values (for fast random access and insertion)
 *
 * Remove Strategy: Swap-with-last technique to avoid O(n) shifting
 * - Move last element to the position of element being removed
 * - Update the moved element's index in HashMap
 * - Remove last element from array
 */
class RandomizedSet {
    Map<Integer, Integer> valueToIndex; // Maps value to its index in array
    List<Integer> arr;                   // Stores actual values for random access

    public RandomizedSet() {
        valueToIndex = new HashMap<>();
        arr = new ArrayList<>();
    }

    public boolean insert(int val) {
        // Check if value already exists
        if (valueToIndex.containsKey(val)) return false;

        // Add to end of array
        arr.add(val);
        int len = arr.size();

        // Map value to its index
        valueToIndex.put(val, len - 1);
        return true;
    }

    public boolean remove(int val) {
        // Check if value exists
        if (!valueToIndex.containsKey(val)) return false;

        // Get index of element to remove
        int index = valueToIndex.get(val);
        int lastIndex = arr.size() - 1;
        int lastValue = arr.get(lastIndex);

        // Remove from map first
        valueToIndex.remove(val);

        // Swap element to remove with last element
        arr.set(index, lastValue);

        // Update moved element's index (only if it's not the same element)
        if (index != lastIndex) {
            valueToIndex.put(lastValue, index);
        }

        // Remove last element
        arr.remove(lastIndex);
        return true;
    }

    public int getRandom() {
        // Generate random index and return element
        int len = arr.size();
        int randomVal = new Random().nextInt(len);
        return arr.get(randomVal);
    }
}
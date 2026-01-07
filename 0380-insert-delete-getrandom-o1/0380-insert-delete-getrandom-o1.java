class RandomizedSet {
    Map<Integer, Integer> valueToIndex;
    List<Integer> arr;
    public RandomizedSet() {
        valueToIndex = new HashMap<>();
        arr = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if (valueToIndex.containsKey(val)) return false;
        arr.add(val);
        int len = arr.size();
        valueToIndex.put(val, len - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if (!valueToIndex.containsKey(val)) return false;
        int index = valueToIndex.get(val);
        int lastIndex = arr.size() - 1;
        int lastValue = arr.get(lastIndex);

        valueToIndex.remove(val);
        arr.set(index, lastValue);
        if (index != lastIndex) valueToIndex.put(lastValue, index);
        arr.remove(lastIndex);
        return true;
    }
    
    public int getRandom() {
        int len = arr.size();
        int randomVal = new Random().nextInt(len);

        return arr.get(randomVal);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
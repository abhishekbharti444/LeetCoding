class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = (2 * k) + 1;

        return ceil(n/(double)side) * ceil(m/(double)side);
    }
};
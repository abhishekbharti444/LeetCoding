class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int empti = 0;
        int res = 0;
        while (filled > 0) {
            res += filled;
            empti += filled;
            filled = empti / numExchange;
            empti = empti % numExchange;
        }
        return res;
    }
}
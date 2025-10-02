class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int empti = 0;
        int res = 0;
        while (numBottles > 0 || empti >= numExchange) {
            res += numBottles;
            empti += numBottles;
            numBottles = 0;
            if (empti >= numExchange) {
                numBottles = 1;
                empti -= numExchange;
                numExchange++;
            }
        }
        return res;
    }
}
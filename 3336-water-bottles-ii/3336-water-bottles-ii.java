class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        // Approach: Simulate the process - drink all bottles, then exchange empties
        // Key insight: Exchange rate increases after each exchange operation
        
        int totalDrunk = 0;
        int emptyBottles = 0;
        
        while (numBottles > 0 || emptyBottles >= numExchange) {
            // Drink all available full bottles
            totalDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            
            // Exchange empties for one full bottle if possible
            if (emptyBottles >= numExchange) {
                numBottles = 1;                    // Get 1 full bottle
                emptyBottles -= numExchange;       // Use required empties
                numExchange++;                     // Exchange rate increases
            }
        }
        
        return totalDrunk;
    }
}
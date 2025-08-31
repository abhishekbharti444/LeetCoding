class Solution {
public:
    /*
    SOLUTION APPROACH:
        1. Greedy Strategy: Form balanced shipments as soon as possible to maximize count
        
        2. Key Insight: A shipment is balanced if last_weight < max_weight_in_shipment
        This requires at least 2 parcels (length >= 2)
        
        3. Algorithm:
        - Extend current shipment by adding each parcel
        - Track current shipment length and maximum weight seen so far
        - When current parcel weight < current maximum AND length >= 2:
            * We found a balanced shipment - increment count
            * Reset for next potential shipment (length=0, max=INT_MIN)
        - Continue until all parcels processed
        
        4. Greedy Correctness: Taking the earliest possible balanced shipment never hurts
        because it leaves maximum flexibility for future shipments
        
        5. Edge Case: Single parcel shipments are invalid (need length >= 2 for comparison)

    Time Complexity: O(n) - single pass through array
    Space Complexity: O(1) - only tracking current shipment state
    */

    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int res = 0;
        int curr_len = 0;
        int curr_max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            curr_len++;
            curr_max = max(curr_max, weight[i]);
            if (curr_len < 2) continue;
            if (weight[i] < curr_max) {
                res++;
                curr_len = 0;
                curr_max = INT_MIN;
            }
        }
        return res;
    }
};
class Solution {
public:
    /*
     * Approach: Reverse Simulation with Greedy Optimization
     * 
     * Work backwards from (tx, ty) to (sx, sy) by reversing the doubling operations.
     * At each step, the current state uniquely determines the previous state:
     * 
     * 1. If tx > ty:
     *    - If tx > 2*ty: Must have doubled x → reverse with tx/2
     *    - If tx ≤ 2*ty: Must have added ty to x → reverse with tx-ty
     * 
     * 2. If ty > tx: Similar logic for y coordinate
     * 
     * 3. If tx == ty: Use source coordinates to resolve ambiguity
     * 
     * Key insight: No branching needed - each state has unique previous state
     *
     * DOUBT 1: Why always reduce the larger coordinate? Why not explore both directions?
     * CLARIFICATION: Each state has a UNIQUE previous state determined by the coordinate relationship:
     * - The move rules create deterministic reverse paths
     * - No branching needed since current state tells us exactly which operation was used
     * 
     * DOUBT 2: Why use tx /= 2? This doesn't seem to match the problem's movement rules.
     * CLARIFICATION: This problem involves DOUBLING coordinates, not adding max(x,y):
     * - Forward moves: (x,y) → (2x,y) or (x,2y)
     * - Backward moves: Reverse the doubling with /= 2
     * 
     * DOUBT 3: When tx == ty, why can we decide the direction using source coordinates?
     * CLARIFICATION: Equal coordinates create ambiguity, but source constraints resolve it:
     * - If sx == 0: Path must reach x=0, so we can safely reduce tx to 0
     * - If sy == 0: Path must reach y=0, so we can safely reduce ty to 0
     * - If both sx,sy > 0: Impossible to reach from equal coordinates
     * 
     * Time: O(log(max(tx, ty))), Space: O(1)
     */
    
    int minMoves(int sx, int sy, int tx, int ty) {
        // Special case: starting from origin, only origin is reachable
        if (sx == 0 && sy == 0) {
            return (tx == 0 && ty == 0) ? 0 : -1;
        }

        int res = 0;
        while (tx != sx || ty != sy) {
            // Impossible if target is smaller than source
            if (tx < sx || ty < sy) return -1;
            
            if (tx > ty) {
                // Case 1: tx significantly larger than ty
                if (tx > 2 * ty) {
                    // Must have reached here by doubling x repeatedly
                    // Can only reverse if tx is even
                    if (tx % 2 == 0) tx /= 2;
                    else return -1;
                }
                else {
                    // Case 2: tx close to ty, must have added ty to x
                    tx -= ty;
                }
            }
            else if (ty > tx) {
                // Mirror logic for y coordinate
                if (ty > 2 * tx) {
                    // Must have doubled y repeatedly
                    if (ty % 2 == 0) ty /= 2;
                    else return -1;
                }
                else {
                    // Added tx to y
                    ty -= tx;
                }
            }
            else {
                // tx == ty: Ambiguous case, use source to decide direction
                if (sx == 0) {
                    tx = 0;  // Path must reach x=0, so reduce x
                }
                else if (sy == 0) {
                    ty = 0;  // Path must reach y=0, so reduce y
                }
                else {
                    return -1;  // Can't reach both positive coordinates from equal state
                }
            }

            res++;
        }
        return res;
    }
};

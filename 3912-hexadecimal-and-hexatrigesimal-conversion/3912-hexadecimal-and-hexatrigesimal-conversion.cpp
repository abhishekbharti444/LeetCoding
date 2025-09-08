/*
SOLUTION APPROACH: Base Conversion and String Concatenation

PROBLEM: Given integer n, return concatenation of:
1. Hexadecimal (base-16) representation of n²
2. Hexatrigesimal (base-36) representation of n³

KEY COMPONENTS:
1. Base conversion algorithm for arbitrary bases
2. Mathematical operations: n² and n³
3. String concatenation of results

BASE CONVERSION ALGORITHM:
- Repeatedly divide by base and collect remainders
- Use digit mapping: 0-9 for values 0-9, A-Z for values 10-35
- Build result string by prepending digits (right-to-left extraction)

MATHEMATICAL OPERATIONS:
- n² (square): for hexadecimal conversion
- n³ (cube): for hexatrigesimal conversion

DIGIT MAPPING:
- Base 16: Uses 0-9, A-F (values 0-15)
- Base 36: Uses 0-9, A-Z (values 0-35)
- Single string covers both: "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
*/

class Solution {
public:
    // Generic base conversion function for any base 2-36
    string convertBase(int val, int base) {
        // Handle zero case
        if (val == 0) return "0";
        
        // Digit mapping: 0-9 for 0-9, A-Z for 10-35
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";

        // Extract digits from right to left using modulo and division
        while (val > 0) {
            int rem = val % base;           // Get rightmost digit in target base
            res = digits[rem] + res;        // Prepend digit character to result
            val = val / base;               // Remove processed digit
        }
        
        return res;
    }
    
    string concatHex36(int n) {
        // Convert n² to hexadecimal (base-16)
        string hexResult = convertBase(n * n, 16);
        
        // Convert n³ to hexatrigesimal (base-36)  
        string hex36Result = convertBase(n * n * n, 36);
        
        // Concatenate and return
        return hexResult + hex36Result;
    }
};

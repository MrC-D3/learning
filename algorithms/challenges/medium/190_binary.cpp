// Time: 15m for the easy solution (i.e. no LUT), so consider +5 for the medium.
// Return the bit-wise reversed of n.
// Constraints: __builtin_bitreverse32(n) not allowed.

#include <cstdint>

// If the solution is called many times: Look Up Table (LUT).
class Solution {
public:
    int reverseBits(int n) {
        // Static internal array is better because it's initialized once for all
        //  the instances of Solution.
        static uint8_t reversed[256];
        static bool initialized = false;

        // Initialization boolean-based is better than lambda-based because the
        //  compiler can do more optimization and so create smaller code.
        if (!initialized)
        {
            reversed[0] = 0;
            for (uint8_t i = 1; i != 0; i++) // Overflow, don't use "<256".
            {
                uint8_t byte = i;
                // Reverse 4-bytes groups.
                byte = (byte >> 4) | (byte << 4);
                // Reverse 2-bytes groups.
                byte = ((byte & 0xCC) >> 2) | ((byte & 0x33) << 2);
                // Reverse 1-byte groups.
                byte = ((byte & 0xAA) >> 1) | ((byte & 0x55) << 1);
                reversed[i] = byte;
            }
            initialized = true;
        }

        // DON'T use char: signed on most platforms.
        uint8_t byte3 = reversed[(n >> 24) & 0xFF];
        uint8_t byte2 = reversed[(n >> 16) & 0xFF];
        uint8_t byte1 = reversed[(n >> 8) & 0xFF];
        uint8_t byte0 = reversed[(n >> 0) & 0xFF];
        
        return (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0);
    }
};
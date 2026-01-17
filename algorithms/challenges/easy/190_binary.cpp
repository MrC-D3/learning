// Time: 15m.
// Return the bit-wise reversed of n.
// Constraints: __builtin_bitreverse32(n) not allowed.
// Note: optimize it for many calls; it may be considered a medium task.

#include <iostream>

using namespace std;

// Optimal solution.
class Solution {
public:
    int reverseBits(int n) {
        // Masks must be unsigned so when used (e.g. with &) the result is 
        //  considered unsigned and the shift is logical not arithmetical.
        // So auto is bad because the compiler can treat the literal as signed.
        uint32_t lower_word = 0b00000000000000001111111111111111;
        uint32_t upper_word = 0b11111111111111110000000000000000;
        n = ((n & lower_word) << 16) | ((n & upper_word) >> 16);

        uint32_t even_bytes = 0b00000000111111110000000011111111;
        uint32_t odd_bytes =  0b11111111000000001111111100000000;
        n = ((n & even_bytes) << 8) | ((n & odd_bytes) >> 8);

        uint32_t even_nibbles = 0b00001111000011110000111100001111;
        uint32_t odd_nibbles =  0b11110000111100001111000011110000;
        n = ((n & even_nibbles) << 4) | ((n & odd_nibbles) >> 4);

        uint32_t even_couples = 0b00110011001100110011001100110011;
        uint32_t odd_couples =  0b11001100110011001100110011001100;
        n = ((n & even_couples) << 2) | ((n & odd_couples) >> 2);

        uint32_t even_ones = 0b01010101010101010101010101010101;
        uint32_t odd_ones =  0b10101010101010101010101010101010;
        n = ((n & even_ones) << 1) | ((n & odd_ones) >> 1);

        return n;
    }
};

class Solution_v0 {
public:
    int reverseBits(int n) {
        int result = 0;
        // Shift the lowest part.
        for (int i = 1; i < 16; i++)
        {
            // Create mask for bit_i, starting from 1.
            auto mask = 1 << i;
            // Isolate bit-i using the mask.
            auto isolated = n & mask;
            // Shift the isolated bit to 31-2*i.
            auto shifted = isolated << (31 - 2*i);
            // |= with the final result, that is initialized at 0.
            result |= shifted;
        }
        // Shift the highest part.
        for (int i = 16; i < 31; i++)
        {
            // Create mask for bit_i, starting from 16.
            auto mask = 1 << i;
            // Isolate bit-i using the mask.
            auto isolated = n & mask;
            // Shift the isolated bit to 31-2*i.
            auto shifted = isolated >> (2*i - 31);
            // |= with the final result, that is initialized at 0.
            result |= shifted;
        }
        return result;
    }
};

// Time: 15m. OUT.
// Return the bit-wise reversed of n. Then optimize it for many calls?
// Constraints: __builtin_bitreverse32(n) not allowed.

#include <iostream>

using namespace std;


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

class Solution_v1 { // Optimal solution.
public:
    int reverseBits(int n) {
        // Masks must be unsigned so when used (&) the result is considered 
        //  unsigned and the shift is logical not arithmetical.
        // Here auto is risky because the compiler can treat the literal as int.
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

int main()
{
    Solution s;
    for (uint8_t i = 1; i != 0; i++)
    {
        cout << (uint8_t)i << " : " << (uint8_t) (s.reversed[i]) << endl;
    }

    return 0;
}
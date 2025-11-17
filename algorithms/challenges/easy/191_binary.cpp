// Time: 15m. OK.

// The Brian Kernighan's algorithm.
// Better performance: O(W1), where W1 is the number of set bits of N.
// Works with negative input too: shift is risky with negative numbers.
class Solution {
public:
    int hammingWeight(int n) {
        int hamming_weight = 0;
        while (n != 0)
        {
            // Subtracting 1 unsets the lowest set bit.
            hamming_weight &= (n - 1);
            hamming_weight += 1;
        }

        return hamming_weight;
    }
};

// O(W), where W is the number of bits of N.
class Solution {
public:
    int hammingWeight(int n) {
        int hamming_weight = 0;
        while (n > 0)
        {
            hamming_weight += (n & 1);
            n >>= 1; // >>1, means /2.
        }

        return hamming_weight;
    }
};
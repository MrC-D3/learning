// Time: 20m. OUT.
// Find the lowest version in [1, n] that returns isBadVersion(V)==true.
// Constraints: n in [1, 2^31 - 1].

class Solution_iterative {
public:
    // The API isBadVersion is defined for you.
    bool isBadVersion(int version)
    {}

    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        while (start < end)
        {
            // Doing directly (start+end)/2 can cause overflow!
            auto mid = start + ((end - start) / 2);
            if (isBadVersion(mid))
                end = mid;
            else
                start = mid + 1;
        }

        return start;
    }
};

class Solution {
public:
    // The API isBadVersion is defined for you.
    bool isBadVersion(int version)
    {}

    int bsearch(int start, int end) 
    {
        if (start >= end)
        {
            return start;
        }

        auto mid = start + ((end - start) / 2);
        if (isBadVersion(mid))
        {
            // Don't exclude mid, so no mid-1.
            return bsearch(start, mid);
        }

        // Here mid can be excluded because for sure it can't be the answer.
        return bsearch(mid + 1, end);
    }

    int firstBadVersion(int n) {
        return bsearch(1, n);
    }
};


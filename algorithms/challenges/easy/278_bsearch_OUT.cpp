// Time: 20m. OUT.
// Find the lowest version V that returns isBadVersion(V)==true.
// Constraints: 1 <= bad <= n <= 231 - 1

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
            auto mid = start + ((end - start) / 2);
            if (isBadVersion(mid))
            {
                end = mid;
                continue
            }

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


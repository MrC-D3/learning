#include <algorithm>
#include <array>
#include <cctype> // For isalnum() and tolower().
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        for ( ; k >= 0 && i >= 0 && j >= 0; k--)
        {
            if (nums2[j] > nums1[i])
            {
                nums1[k] = nums2[j--];
            }
            else
            {
                nums1[k] = nums1[i--];
            }
        }

        // The leftovers from nums1 would be already in nums1.
        for ( ; j >= 0; k--, j--)
        {
            nums1[k] = nums2[j];
        }
    }
};
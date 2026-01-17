// Time: (estimated) 15m. OK.
// Take the 2 largest stones (X, Y) and: if X==Y they are destroyed, but if X>Y
//  Y is destroyed and X becomes X-Y.
// Constraints: stones.size in [1, 30]; stones[i] in [1, 1000].

#include <queue>

using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // The comparison function used by a priority queue answers to: who is
        //  pushed down the heap? By default it uses less<int>, so less priority
        //  elements are pushed down.
        // The queue is implemented using a vector<T> by default.
        // Building the queue using the c'tor is faster than doing later.
        priority_queue<int> max_heap(stones.begin(), stones.end());
        // Alternative: make_heap(), push_heap(), pop_heap(), etc. on stones.

        // O(nlogn).
        while (max_heap.size() > 1)
        {
            auto stone_big = max_heap.top(); // Largest.
            max_heap.pop();
            auto stone_small = max_heap.top(); // 2nd largest.
            max_heap.pop();
            if (stone_big != stone_small)
                max_heap.push(stone_big - stone_small);
        }

        return max_heap.size() == 0 ? 0 : max_heap.top();
    }
};
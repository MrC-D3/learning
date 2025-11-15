// Time: 15m. Ok.
// Return true if Intervals don't overlap.
// Constraints: vector<>.size in [0, 500]; start/end in [0, 10^6].

#include <vector>
#include <algorithm>

using namespace std;

/* Definition of Interval. */

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
          [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        });

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i-1].end)
                return false;
        }

        return true;
    }
};

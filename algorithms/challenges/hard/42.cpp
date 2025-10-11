#include <vector>
#include <stack>
#include <list>


using namespace std;

// Two pointers solution: not intuitive, but complexity is O(N) for Time and
//  O(1) for Space.
class Solution
{
  public:
    int trap(vector<int>& height) 
    {
        auto N = height.size();
        
        // N can be just 1, so memory-risky to start directly from 1 and N-2.
        auto left = 0;
        auto right = N - 1;
        // Since we can't start from 1 and N-2, _max must be initialized at 0.
        int left_max = 0, right_max = 0;

        int water = 0;
        while (left < right) 
        {
            // This still surprises me, but it works.
            //  Choosing the lowest side, assure there's a boundary on the other
            //  side. Even when [left]==[right], because it means either just an 
            //  update of right_max or that there is right_max>[right], so also
            //  right_max>[left]. And if right went from that right_max to 
            //  current right, it means there is also a left_max>=right_max.
            if (height[left] < height[right]) // Process left side
            {
                // Now check there's a boundary also on this side.
                if (height[left] >= left_max) // There isn't a boundary.
                {
                    left_max = height[left];
                } 
                else // There's a boundary.
                {
                    water += left_max - height[left];
                }
                left++;
            } 
            else // Process right side
            {
                if (height[right] >= right_max) 
                {
                    right_max = height[right];
                } 
                else 
                {
                    water += right_max - height[right];
                }
                right--;
            }
        }

        return water;
    }
};

// Time O(N), but also Space O(N).
class Solution_v2
{
  public:
    // This solution thinks cell by cell and it doesn't rely on [i-1] and [i+1].
    // It's like: this cell is part of a trap whose water level is driven by the
    //  shortest between the 2 limits of the trap and the floor level at [i].
    int trap(vector<int>& height) 
    {
        auto N = height.size();
        vector<int> left_highest(N, 0);
        vector<int> right_highest(N, 0);

        auto current_left_highest = height[0];
        auto current_right_highest = height[N-1];
        for (int i = 1; i < N; i++)
        {
            // Left.
            left_highest[i] = current_left_highest;
            current_left_highest = max(height[i], current_left_highest);
            // Right.
            right_highest[N-1-i] = current_right_highest;
            current_right_highest = max(height[N-1-i], current_right_highest);
        }

        int to_return = 0;
        for (int i = 1; i < N-1; i++)
        {
            auto trapped = min(left_highest[i], right_highest[i]) - height[i];
            if (trapped > 0)
            {
                to_return += trapped;
            }
        }

        return to_return;
    }
};

// O(N^2) because of the inner loop.
class Solution_v1
{
  public:
    int trap(vector<int>& height) 
    {
        int to_return = 0;
        list<int> indexes;
        
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] == 0)
            {
                continue;
            }

            auto second_highest = 0;
            for (auto it = indexes.begin(); it != indexes.end(); )
            {
                auto j = *it;
                auto b = i - j - 1;
                auto h = min(height[i], height[j]);
                auto volume = b * h - b * second_highest;
                to_return += volume;
                second_highest = max(second_highest, height[j]);

                if (height[i] < height[j])
                {
                    break;
                }
                if (height[i] == height[j])
                {
                    indexes.erase(it);
                    break;
                }
                if (height[i] > height[j])
                {
                    it = indexes.erase(it);
                    // Keep going.
                }
            }

            indexes.push_front(i);
        }

        return to_return;
    }
};

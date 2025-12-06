// Time 20m. OK.
// Flood Fill.
//  Write color in image[sr][sc] and all its adjacent cells, where "adjacent"
//  means the cell shares a border with [sr][sc] or with an adjacent cell.
// Constraints: 1 <= rows, columns <= 50; 0 <= image[i][j], color < 2^16; 
//  0 <= sr < rows; 0 <= sc < columns.

#include <vector>
#include <stack>
#include <array>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target_color = image[sr][sc];
        if (target_color == color)
        {
            return image;
        }

        using Point = pair<int,int>; // No need to define a new class.
        stack<Point> points; // Queue can be more cache friendly.
        int rows = image.size();
        int columns = image[0].size();
        vector<Point> directions{{ // Yes, array<> requires double brakets.
          {-1,0}, {0,1}, {1,0}, {0,-1} // Up, Right, Down, Left.
        }};

        // Don't push what has to be colored, but the starting points to keep 
        //  searching. So, you avoid pushing several times the same point.
        image[sr][sc] = color;
        points.emplace(sr, sc);
        while (!points.empty())
        {
            auto [r, c] = points.top();
            points.pop();

            for (auto [dr, dc] : directions)
            {
                auto ra = r + dr;
                auto rc = c + dc;
                if (ra >= 0 && ra < rows 
                  && rc >= 0 && rc < columns
                  && image[ra][rc] == target_color)
                {
                    image[ra][rc] = color;
                    points.emplace(ra, rc);
                }                
            }
        }

        return image;
    }
};


struct Point
{
    int r;
    int c;
};

class Solution_v0 {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target_color = image[sr][sc];
        if (target_color == color)
        {
            return image;
        }

        stack<Point> points;
        int rows = image.size();
        int columns = image[0].size();

        points.emplace(sr, sc);
        while (!points.empty())
        {
            auto point = points.top();
            points.pop();
            image[point.r][point.c] = color;

            if (point.r - 1 >= 0 && image[point.r-1][point.c] == target_color)
            {
                points.emplace(point.r - 1, point.c);
            }
            if (point.c + 1 < columns && image[point.r][point.c+1] == target_color)
            {
                points.emplace(point.r, point.c+1);
            }
            if (point.r + 1 < rows && image[point.r+1][point.c] == target_color)
            {
                points.emplace(point.r + 1, point.c);
            }
            if (point.c - 1 >= 0 && image[point.r][point.c-1] == target_color)
            {
                points.emplace(point.r, point.c-1);
            }
        }

        return image;
    }
};
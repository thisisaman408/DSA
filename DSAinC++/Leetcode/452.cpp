#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort the balloons based on their end points
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int endPos = points[0][1];
        
        // Iterate through the balloons and count the number of arrows needed
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon's start point is beyond the end position, we need another arrow
            if (points[i][0] > endPos) {
                arrows++;
                endPos = points[i][1]; // Update the end position
            }
        }
        
        return arrows;
    }
};

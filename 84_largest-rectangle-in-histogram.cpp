#include "util.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int rtn = 0;
        heights.push_back(0);
        vector<int> queue;
        for(int i = 0; i < heights.size(); i++) {
            while (!queue.empty() && heights[i] < heights[queue.back()]) {
                int j = queue.back();
                queue.pop_back();
                int h = heights[j];
                int w = queue.empty() ? i : i - queue.back() - 1;
                rtn = max(rtn, h * w);
            }
            queue.push_back(i);
        }
        return rtn;
    }
};

int main() {
    vector<int> heights;
    Solution slu;
    heights = {4,2,0,3,2,5};
    cout << slu.largestRectangleArea(heights) << endl;
    heights = {2,1,2};
    cout << slu.largestRectangleArea(heights) << endl;
    heights = {2,1,5,6,2,3};
    cout << slu.largestRectangleArea(heights) << endl;
    heights = {2,4};
    cout << slu.largestRectangleArea(heights) << endl;
    return 0;
}
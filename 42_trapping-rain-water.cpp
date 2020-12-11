#include "util.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<vector<int>> intervals;
        int l = -1, r = -1;
        for(int i = 0; i < height.size(); i++) {
            if (l != -1 && i != 0 && height[i-1]<height[i]) {
                r = i;
                if (i == height.size() - 1 && l != -1 && l < r) intervals.push_back(vector<int>{l, r});
            }
            if (i+1 < height.size() && height[i] > height[i+1]) {
                if (l != -1 && r != -1 && l < r) {
                    intervals.push_back(vector<int>{l, r});
                    l = i;
                }
                if (i == 0 || l == -1) l = i;
            }
        }
        int rtn = 0;
        for(auto interval: intervals) {
            int b = interval[0], e = interval[1];
            int lb = min(height[b], height[e]);
            for(int j = b + 1; j < e; j++) {
                rtn += lb - height[j];
            }
        }
        return rtn;
    }
};

int main() {
    Solution slu = Solution();
    vector<int> height;
    //height = vector<int>{1, 0, 1};
    //cout << slu.trap(height) << endl;
    //height = vector<int>{0, 1, 0};
    //cout << slu.trap(height) << endl;
    //height = vector<int>{1,1,0,2};
    //cout << slu.trap(height) << endl;
    //height = vector<int>{0,1,1,2};
    //cout << slu.trap(height) << endl;
    //height = vector<int>{2,1,0};
    //cout << slu.trap(height) << endl;
    //height = vector<int>{0,1,0,2,1,0,1,3,2,1,2,1};
    //cout << slu.trap(height) << endl;
    height= vector<int>{4,2,0,3,2,5};
    cout << slu.trap(height) << endl;
    return 0;
}
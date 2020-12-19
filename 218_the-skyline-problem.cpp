#include "util.h"
#include <deque>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        deque<vector<int>> stack;
        vector<vector<int>> rst;
        sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int level = 0;
        for(const vector<int>& building : buildings) {
            int h = building[2];
            int s = building[0];
            while (!stack.empty() && stack.front()[0] < s) {
                // pop 
                assert(stack.front()[1] <= level);
                if (stack.front()[1] == level) {
                    // update level to second highest
                    if (stack.size() == 1) level = 0;
                    else {
                        int ptr = 1;
                        for(int i = 1; i < stack.size(); i++) {
                            if (stack[i][1] > stack[ptr][1]) ptr = i;
                        }
                        level = stack[ptr][1];
                    }
                }
                int t = stack.front()[0];
                int sh = stack.front()[1];
                stack.pop_front();

                // insert a record
                if (sh > level) {
                    if (rst.back()[0] == t) rst.back()[1] = min(rst.back()[1], level);
                    else rst.push_back(vector<int>{t, level});
                }
            }

            // push
            if (h > level) {
                if (!rst.empty() && rst.back()[0] == s) rst.back()[1] = max(rst.back()[1], h);
                else rst.push_back(vector<int>{s, h});
                level = rst.back()[1];
            }
            int t = building[1];
            if (stack.empty()) {
                stack.push_back(vector<int>{t, h});
            } else {
                deque<vector<int>>::iterator itr;
                for(itr = stack.begin(); itr != stack.end(); itr++) {
                    if ((*itr)[0] >= t) {
                        stack.insert(itr, vector<int>{t, h});
                        break;
                    }
                }
                if (itr == stack.end()) stack.push_back(vector<int>{t, h});
            }
        }
        while (!stack.empty()) {
            // pop 
            assert(stack.front()[1] <= level);
            if (stack.front()[1] == level) {
                // update level to second highest
                if (stack.size() == 1) level = 0;
                else {
                    int ptr = 1;
                    for(int i = 1; i < stack.size(); i++) {
                        if (stack[i][1] > stack[ptr][1]) ptr = i;
                    }
                    level = stack[ptr][1];
                }
            }
            int t = stack.front()[0];
            int h = stack.front()[1];
            stack.pop_front();

            // insert a record
            if (h > level) {
                if (rst.back()[0] == t) rst.back()[1] = min(rst.back()[1], level);
                else rst.push_back(vector<int>{t, level});
            }
        }
        return rst;
    }
};

int main() {
    vector<vector<int>> buildings, skyline;
    Solution slu;
    buildings = {
        {0,2,3},
        {2,5,3}
    };
    skyline = slu.getSkyline(buildings);
    for(auto s : skyline) {
        cout<<integerVectorToString(s)<<endl;
    }

    buildings = {
        {2,9,10},
        {3,7,15},
        {5,12,12},
        {15,20,10},
        {19,24,8}
    };
    skyline = slu.getSkyline(buildings);
    for(auto s : skyline) {
        cout<<integerVectorToString(s)<<endl;
    }
    return 0;
}
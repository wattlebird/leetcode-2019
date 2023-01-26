#include "util.h"
#include <set>
#include <algorithm>

using namespace std;

struct Comp {
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
        return lhs[1] < rhs[1];
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 1;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });

        multiset<vector<int>, Comp> Q;
        int rtn = 0;
        for(int i = 0; i < intervals.size(); i++) {
            while (Q.size() > 0) {
                vector<int> top = *(Q.begin());
                if (top[1] <= intervals[i][0]) Q.erase(Q.begin());
                else break;
            }
            Q.insert(intervals[i]);
            rtn = max(int(Q.size()), rtn);
        }
        
        return rtn;
    }
};

int main() {
    Solution slu;
    vector<vector<int>> intervals;
    intervals = {
        {5, 8}, {6, 8}
    };
    cout << slu.minMeetingRooms(intervals) << endl;
    intervals = {
        {11, 20}, {4, 19}, {13, 17}, {6, 13}
    };
    cout << slu.minMeetingRooms(intervals) << endl;
    intervals = {
        {0, 30}, {5, 10}, {15, 20}
    };
    cout << slu.minMeetingRooms(intervals) << endl;
    intervals = {
        {7, 10}, {2, 4}
    };
    cout << slu.minMeetingRooms(intervals) << endl;
    return 0;
}
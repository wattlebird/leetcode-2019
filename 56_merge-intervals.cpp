#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        if (intervals.size() <= 1) return intervals;

        vector<Interval> rtn = {intervals[0]};
        for (size_t i = 1; i != intervals.size(); i++) {
            if (rtn.back().end >= intervals[i].start) {
                if (rtn.back().end < intervals[i].end) rtn.back().end = intervals[i].end;
            } else rtn.push_back(intervals[i]);
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<Interval> intervals = stringToIntervalVector(line);
        
        vector<Interval> ret = Solution().merge(intervals);

        string out = intervalVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
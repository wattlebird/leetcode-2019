#include <iostream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            return vector<Interval> {newInterval};
        }
        if (intervals.back().start <= newInterval.start) intervals.push_back(newInterval);
        else {
            for (vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); itr++) {
                if (itr->start > newInterval.start) {
                    intervals.insert(itr, newInterval);
                    break;
                }
            }
        }
        
        vector<Interval> rtn = {intervals[0]};
        for (size_t i = 1; i != intervals.size(); i++){
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
        getline(cin, line);
        vector<int> t = stringToIntegerVector(line);
        Interval newInterval = Interval(t[0], t[1]);
        vector<Interval> ret = Solution().insert(intervals, newInterval);

        string out = intervalVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
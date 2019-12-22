#include "util.h"

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        vector<int>::const_iterator b = nums.begin(), e = nums.end() - 1, m, s, t;
        if (*b == *e) {
            if (nums.front() == target) return true;
            while (b != e && *b == *e) {
                e--;
            }
            if (b == e) return false;
        }
        if (*b > *e) {
            s = b, t = e;
            while (t - s > 1) {
                m = s + (t - s) / 2;
                if (*m == target) return true;
                else if (*m >= *s) s = m;
                else t = m;
            }
            if (*s < target) return false;
            if (*t > target) return false;
            if (nums.front() <= target) {b = nums.begin(); e = t;}
            else {b = t; e = nums.end();}
        } else {
            e++;
        }
        while (e - b > 1) {
            m = b + (e - b) / 2;
            if (*m == target) return true;
            else if (*m > target) e = m;
            else b = m;
        }
        return *b == target;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
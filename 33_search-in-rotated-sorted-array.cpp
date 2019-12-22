#include "util.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::const_iterator b, e, m;
        if (nums.front() > nums.back()) {
            b = nums.begin(), e = nums.end() - 1;
            while (e - b > 1) {
                m = b + (e - b) / 2;
                if (*m < *b) e = m;
                else b = m;
            }
            if (*b < target) return -1;
            if (*e > target) return -1;
            m = e;
            if (nums.front() <= target) {b = nums.begin(); e = m;}
            else {b = m; e = nums.end();}
        } else {
            b = nums.begin();
            e = nums.end();
        }
        while (e - b > 1) {
            m = b + (e - b) / 2;
            if (*m == target) return m-nums.begin();
            else if (*m > target) e = m;
            else b = m;
        }
        if (*b != target) return -1;
        else return b - nums.begin();
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
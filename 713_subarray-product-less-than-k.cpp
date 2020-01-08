#include "util.h"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        int cur = 1, cnt = 0;
        for (int l = 0, r = l; l < nums.size(); l++) {
            r = l < r ? r : l;
            while (cur < k && r < nums.size()) {
                cur *= nums[r++];
            }
            if (cur >= k && r != l) {cur /= nums[--r];}
            cnt += (r-l);
            if (r != l) cur /= nums[l];
        }
        return cnt;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().numSubarrayProductLessThanK(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
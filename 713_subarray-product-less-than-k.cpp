#include "util.h"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int b = 0, e = 0, cnt = 0, prod = 1;
        while (b < nums.size()) {
            e = max(e, b);
            while (prod < k && e < nums.size()) {
                prod *= nums[e++];
            }
            cnt += e - b;
            if (e != b && prod >= k) cnt--;
            prod /= nums[b++];
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
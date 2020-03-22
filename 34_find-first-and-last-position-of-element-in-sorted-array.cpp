#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1,-1};
        int b = 0, e = nums.size();
        while (b != e) {
            int m = b + (e - b) / 2;
            if (nums[m] >= target) {
                e = m;
            } else {
                b = m + 1;
            }
        }
        if (b == nums.size() || nums[b] != target) return vector<int> {-1, -1};
        else {
            do {e++;} while (e < nums.size() && nums[e] == target);
            return vector<int> {b, e-1};
        }
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
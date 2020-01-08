#include "util.h"

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int rtn = 0;
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] + nums[2] >= target) return 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i+1;
            while (j < nums.size() - 1) {
                auto itr = lower_bound(nums.begin() + j, nums.end(), target - (nums[i] + nums[j]));
                if (itr - 1 > nums.begin() + j) {
                    rtn += (itr - nums.begin()) - j - 1;
                }
                j++;
            }
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumSmaller(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
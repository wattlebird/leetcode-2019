#include "util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rtn;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < int(nums.size() - 2); i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int remaining = 0 - nums[i];
            int j = i+1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == remaining) {
                    rtn.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    do {j++;} while (j < nums.size() && nums[j-1] == nums[j]);
                    do {k--;} while (k > i && nums[k+1] == nums[k]);
                }
                else if (nums[j] + nums[k] > remaining) do {k--;} while (k > i && nums[k+1] == nums[k]);
                else do {j++;} while (j < nums.size() && nums[j-1] == nums[j]);
            }
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<vector<int>> ret = Solution().threeSum(nums);

        for(vector<int> r : ret) {
            string out = integerVectorToString(r);
            cout << out << endl;
        }
    }
    return 0;
}
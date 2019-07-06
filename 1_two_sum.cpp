#include <iostream>
#include <map>
#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> lut = map<int, int>();
        for(size_t i = 0; i != nums.size(); i++) {
            lut[nums[i]] = i;
        }
        vector<int> rtn = vector<int>(2);
        for(size_t i = 0; i != nums.size(); i++) {
            int t = target - nums[i];
            if (lut.count(t) != 0 && lut[t] != i) {
                rtn[0] = i;
                rtn[1] = lut[t];
                return rtn;
            }
        }
        return vector<int>();
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
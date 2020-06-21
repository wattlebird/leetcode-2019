#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        int n1 = nums[0], n2 = nums[1], n1c = 0, n2c = 0;
        for(int n: nums) {
            if (n != n2 && n1c == 0) n1 = n;
            else if (n != n1 && n2c == 0) n2 = n;

            if (n == n1) n1c++;
            else if (n == n2) n2c++;
            else {
                n1c--;
                n2c--;
            }
        }
        vector<int> rtn;
        n1c = 0, n2c = 0;
        for(int n: nums) {
            if (n == n1) n1c++;
            if (n == n2) n2c++;
        }
        if (n1c > nums.size() / 3) rtn.push_back(n1);
        if (n1 != n2 && n2c > nums.size() / 3) rtn.push_back(n2);
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<int> ret = Solution().majorityElement(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
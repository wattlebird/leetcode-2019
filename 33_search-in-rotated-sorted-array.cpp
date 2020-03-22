#include "util.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int b=0, e=nums.size();
        if (nums.front() > nums.back()) {
            while (e - b > 1) {
                int m = b + (e - b) / 2;
                if (nums[m] > nums.front()) b = m;
                else e = m;
            }
            if (nums.front() <= target) {
                b = 0;
            } else {
                b = e;
                e = nums.size();
            }
        }
        
        while (b != e) {
            int m = b + (e - b) / 2;
            if (nums[m] >= target) e = m;
            else b = m + 1;
        }
        if (b < nums.size() && nums[b] == target) return b;
        else return -1;
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
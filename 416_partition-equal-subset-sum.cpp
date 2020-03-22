#include "util.h"
#include <set>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        multiset<int> S;
        set<int> T;
        int target = 0;
        for(int n : nums) {
            target+=n;
            S.insert(n);
        }
        if (target & 0x1) return false;
        else target /= 2;

        for(int n : S) {
            vector<int> temp;
            if (T.count(n) == 0) temp.push_back(n);
            if (n == target) return true;
            for(int m : T) {
                if (m + n == target) return true;
                if (T.count(m+n) == 0) temp.push_back(m+n);
            }
            for(int m : temp) T.insert(m);
        }
        return false;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().canPartition(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
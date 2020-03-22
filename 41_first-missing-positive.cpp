#include "util.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cur=0, pos=0;
        while (cur != nums.size()) {
            if(nums[cur] <= 0) {
                swap(nums[pos++], nums[cur]);
            }
            cur++;
        }
        cur = pos;
        if (pos == nums.size()) return 1;
        int i, expect = 1;
        for (i = pos; i < nums.size() - 1; i++) {
            int cache = nums[i];
            pos = i;
            for (int j = i + 1; j < nums.size(); j++) if (nums[j] < cache) pos++;
            while(pos != i && nums[pos] == cache) pos++;
            swap(cache, nums[pos]);
            while (pos != i) {
                pos = i;
                for (int j = i + 1; j < nums.size(); j++) if (nums[j] < cache) pos++;
                while(pos != i && nums[pos] == cache) pos++;
                swap(cache, nums[pos]);
            }
            if (expect != nums[i] && expect != nums[i] + 1) return expect;
            else if (expect == nums[i]) expect++;
        }
        if (expect == nums[i]) return expect + 1;
        else return expect;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
#include "util.h"
#include <queue>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> S;
        vector<int> l(nums.size(), -1), r(nums.size(), -1);
        int b = nums.size(), e = 0;
        for(int i = 0; i < nums.size(); i++) {
            while (!S.empty() && nums[S.back()] > nums[i]) {
                l[i] = S.back();
                S.pop_back();
            }
            if (l[i] != -1) {
                b = min(l[i], b);
            }
            S.push_back(i);
        }
        S.clear();
        for(int i = nums.size() - 1; i >= 0; i--) {
            while (!S.empty() && nums[S.back()] < nums[i]) {
                r[i] = S.back();
                S.pop_back();
            }
            if (r[i] != -1) {
                e = max(r[i], e);
            }
            S.push_back(i);
        }
        return b < e ? e - b + 1 : 0;
    }
};

int main() {
    Solution slu;
    vector<int> arr = {1,2,4,5,3};
    cout << slu.findUnsortedSubarray(arr) << endl;
    arr = {1,1,1};
    cout << slu.findUnsortedSubarray(arr) << endl;
    arr = {2,2,1,1};
    cout << slu.findUnsortedSubarray(arr) << endl;
    arr = {1,3,5,4,2};
    cout << slu.findUnsortedSubarray(arr) << endl;
    return 0;
}
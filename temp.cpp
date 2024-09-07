#include "util.h"
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> S;
        map<int, int> M;
        int cnt = 0, pre = 0, cur = 0;
        for(int a: nums) {
            S.insert(a);
        }
        while(cur < nums.size()) {
            M[nums[cur]]++;
            while (M.size() == S.size()) {
                cnt += nums.size() - cur;
                if (--M[nums[pre]] == 0) M.erase(nums[pre]);
                pre++;
            }
            cur++;
        }
        return cnt;
    }
};


int main() {
    vector<int> num;
    Solution slu;
    num = {1586,1332,1055,1586,1586,1861,892,1445};
    cout << slu.countCompleteSubarrays(num)<< endl;
    return 0;
}
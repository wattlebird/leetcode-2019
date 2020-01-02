#include "util.h"
#include <set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>::iterator itr = S.end();
        for (int i = 0; i < k; i++) {
            S.insert(nums[i]);
            if (itr == S.end()) {
                itr = S.begin();
            } else {
                if (i & 0x1) itr = *itr > nums[i] ? prev(itr) : itr;
                else itr = *itr > nums[i] ? itr : next(itr);
            }
        }
        
        vector<double> rtn;
        for (int i = 0; i + k <= nums.size(); i++) {
            rtn.push_back((k & 0x1) ? *itr : (*itr + *next(itr)) / 2.0);
            
            if (i + k < nums.size()) {
                S.insert(nums[i+k]);
                if (k & 0x1) itr = *itr > nums[i+k] ? prev(itr) : itr;
                else itr = *itr > nums[i+k] ? itr : next(itr);

                if (nums[i] == *itr) itr = (k & 0x1) ? S.erase(itr) : prev(S.erase(itr));
                else {
                    S.erase(nums[i]);
                    if (k & 0x1) itr = *itr > nums[i] ? next(itr) : itr;
                    else itr = *itr > nums[i] ? itr : prev(itr);
                }
            }
        }
        
        return rtn;
    }
private:
    multiset<int> S;
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<double> rtn = Solution().medianSlidingWindow(nums, k);

        string out = doubleVectorToString(rtn);
        cout << out << endl;
    }
    return 0;
}
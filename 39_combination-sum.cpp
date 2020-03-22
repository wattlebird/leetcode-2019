#include "util.h"
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> slu(target+1, vector<vector<int>>());
        for(int c : candidates) {
            for(int i = c; i <= target; i++) {
                if (slu[i-c].empty()) {
                    if (i == c) slu[i].push_back(vector<int>{c});
                } else {
                    for(vector<int> s: slu[i-c]) {
                        vector<int> t(s);
                        t.push_back(c);
                        slu[i].push_back(t);
                    }
                }
            }
        }
        return slu[target];
    }
};

int main() {
    vector<int> candidates;

    candidates = {2,3,6,7};
    auto rst = Solution().combinationSum(candidates, 7);
    for(auto rs: rst) {
        cout<<integerVectorToString(rs)<<endl;
    }
    cout <<endl;
    candidates = {2,3,5};
    rst = Solution().combinationSum(candidates, 8);
    for(auto rs: rst) {
        cout<<integerVectorToString(rs)<<endl;
    }
    cout <<endl;
    return 0;

}
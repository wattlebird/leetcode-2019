#include "util.h"
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> bin;
        for(int c: candidates) {
            bin[c]++;
        }
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>());
        for(auto p: bin) {
            for(int j = 1; j <= p.second; j++) {
                int a = j * p.first;
                vector<int> s(j, p.first);
                for(int i = target; i >= a; i--) {
                    if (i != a && dp[i - a].size() != 0) {
                        for(auto s: dp[i-a]) if (s.back() < p.first) {
                            s.insert(s.end(), j, p.first);
                            dp[i].push_back(s);
                        }
                    } else if (i == a) {
                        dp[i].push_back(vector<int>(j, p.first));
                    }
                }
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> candidates;

    //candidates = {10,1,2,7,6,1,5};
    //auto rst = Solution().combinationSum2(candidates, 8);
    //for(auto rs: rst) {
    //    cout<<integerVectorToString(rs)<<endl;
    //}
    //cout <<endl;
    //candidates = {2,5,2,1,2};
    //rst = Solution().combinationSum2(candidates, 5);
    //for(auto rs: rst) {
    //    cout<<integerVectorToString(rs)<<endl;
    //}
    //cout <<endl;
    candidates = {4,4,2,1,4,2,2,1,3};
    auto rst = Solution().combinationSum2(candidates, 6);
    for(auto rs: rst) {
        cout<<integerVectorToString(rs)<<endl;
    }
    cout <<endl;
    return 0;

}
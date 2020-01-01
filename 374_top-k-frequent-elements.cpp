#include "util.h"
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> G;
        for (int n : nums) G[n]++;

        auto comp = [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> Q(comp);
        for (pair<int, int> p : G) {
            Q.push(p);
        }
        
        vector<int> rtn;
        while(k-- != 0) {rtn.push_back(Q.top().first); Q.pop();}
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
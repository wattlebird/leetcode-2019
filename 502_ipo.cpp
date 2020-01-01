#include "util.h"

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> cp;
        for(size_t i = 0; i != Capital.size(); i++) {
            cp.push_back(pair<int, int>(Profits[i], Capital[i]));
        }
        auto comp = [](pair<int, int>& i1, pair<int, int>& i2){return i1.second == i2.second ? i1.first < i2.first : i1.second < i2.second;};
        sort(cp.begin(), cp.end(), comp);
        auto qcomp = [](pair<int, int>& i1, pair<int, int>& i2){return i1.first < i2.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(qcomp)> Q(qcomp);
        int idx = 0;
        while (idx < cp.size() && cp[idx].second <= W) Q.push(cp[idx++]);
        while (k-- && !Q.empty()) {
            W += Q.top().first;
            Q.pop();
            while (idx < cp.size() && cp[idx].second <= W) Q.push(cp[idx++]);
        }
        return W;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int k = stringToInteger(line);
        getline(cin, line);
        int W = stringToInteger(line);
        getline(cin, line);
        vector<int> Profits = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> Capital = stringToIntegerVector(line);
        
        int ret = Solution().findMaximizedCapital(k, W, Profits, Capital);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
#include "util.h"
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> G;
        for(char c : s) {
            G[c]++;
        }
        auto comp = [](pair<char, int>& a, pair<char, int>& b) {return a.second < b.second;};
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> Q(comp);
        for(pair<char, int> p : G) {
            Q.push(p);
        }
        string rtn = "";
        while (!Q.empty()) {
            auto p = Q.top();
            while (p.second-- != 0) rtn += p.first;
            Q.pop();
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().frequencySort(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
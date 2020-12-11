#include "util.h"
#include <queue>
#include <map>

using namespace std;

typedef unsigned long long ll;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        map<int, int> G;
        for(int n: nums) {
            G[n]+=1;
            if (G[n] > k) return -1;
        }
        dfs(G, 0);
        return rtn == 500 ? -1 : rtn;
    }
    
    bool dfs(map<int, int>& G, int cur) {
        map<int, int>::iterator u = G.begin(), v;
        for(; u != G.end(); u++) {
            if (u->second != 0) {
                break;
            }
        }
        if (u == G.end()) {
            rtn = min(cur, rtn);
            return true;
        }
        u->second -= 1;
        for(v = u; v != G.end(); v++) {
            if (v != u && v->second != 0) {
                v->second -= 1;
                bool r = dfs(G, cur + v->first - u->first);
                v->second += 1;
            }
        }
        u->second += 1;
    }
    
    int rtn = 500;
};


int main() {
    vector<int> num;
    Solution slu;
    num = {1};
    cout << slu.minimumIncompatibility(num, 1)<< endl;
    num = {1,2,1,4};
    cout << slu.minimumIncompatibility(num, 2)<< endl;
    num = {6,3,8,1,3,1,2,2};
    cout << slu.minimumIncompatibility(num, 4)<< endl;
    num = {5,3,3,6,3,3};
    cout << slu.minimumIncompatibility(num, 3)<< endl;
    return 0;
}
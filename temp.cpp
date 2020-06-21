#include "util.h"
#include <queue>
#include <map>

using namespace std;

typedef unsigned long long ll;

class Solution {
public:
    int numOfWays(int n) {
        //unsigned int mod = 1;
        string cur;
        dfs(0, cur);
        map<string, ll> rst;
        if (n == 1) return 12;
        else {
            for(auto p: G) rst[p.first] = 1;
            while (--n > 0) {
                map<string, ll> n;
                for(auto p: rst) {
                    for(auto q: G[p.first]) {
                        n[q] += p.second;
                        //n[q] %= mod;
                    }
                }
                rst = n;
            }
        }
        int rtn = 0;
        for(auto p: rst) {
            rtn += p.second;
        }
        return rtn;
    }
private:
    void dfs(int depth, string& cur) {
        if (depth == 3) {
            string nxt;
            ddfs(cur, nxt);
        } else {
            for(auto c: colors) {
                int flag = false;
                if (cur.size() == 0) {
                    flag = true;
                    cur.push_back(c);
                    dfs(1, cur);
                } else if (cur.back() != c) {
                    flag = true;
                    cur.push_back(c);
                    dfs(depth+1, cur);
                }
                if (flag) cur.pop_back();
            }
        }
    }
    
    void ddfs(const string& cur, string& nxt) {
        if (nxt.size() == 3) {
            if (G.count(cur) == 0) G[cur] = vector<string>{nxt};
            else if (find(G[cur].begin(), G[cur].end(), nxt) == G[cur].end()) G[cur].push_back(nxt);
            return;
        }
        for(int c: colors) {
            int flag = false;
            if (nxt.size() == 0) {
                if (c != cur[0]) {nxt.push_back(c); flag = true;}
            } else {
                if (c != cur[nxt.size()] && c != nxt.back()) {nxt.push_back(c); flag = true;}
            }
            if (flag) {
                ddfs(cur, nxt);
                nxt.pop_back();
            }
        }
    }
    map<string, vector<string>> G;
    vector<char> colors = {'0','1','2'};
};


int main() {
    cout<< Solution().numOfWays(2)<<endl;
     cout<< Solution().numOfWays(3)<<endl;
      cout<< Solution().numOfWays(7)<<endl;
      cout<< Solution().numOfWays(7)<<endl;
       cout<< Solution().numOfWays(5000)<<endl;
    return 0;
}
#include "util.h"
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1000000007;
        auto comp = [speed, efficiency](int i, int j){return speed[i] * efficiency[i] < speed[j] * efficiency[j];};
        vector<int> index(n, 0);
        for( int i = 0; i < n; i++) index[i] = i;
        priority_queue<int, vector<int>, decltype(comp)> Q(index.begin(), index.end(), comp);
        long long rtn = 0, cnt = 0, e = 0, s = 0;
        while (!Q.empty() && cnt < k) {
            int i = Q.top();
            Q.pop();
            if (rtn == 0) {
                e = efficiency[i];
                s = speed[i];
                rtn = (e*s)%mod;
                cnt++;
            } else {
                double ds = speed[i], de = efficiency[i] < e ? e - efficiency[i] : 0;
                if ((de / e) < (ds / (s+ds))) {
                    e = e < efficiency[i] ? e : efficiency[i];
                    s+= speed[i];
                    rtn = (e*s)%mod;
                    cnt++;
                }
            }
        }
        return rtn;
    }
};


int main() {
    vector<int> e = {5,4,3,9,7,2};
    vector<int> s = {2,10,3,1,5,8};
    cout<< Solution().maxPerformance(6, s, e, 2)<<endl;
    cout<< Solution().maxPerformance(6, s, e, 3)<<endl;
    cout<< Solution().maxPerformance(6, s, e, 4)<<endl;
    return 0;
}
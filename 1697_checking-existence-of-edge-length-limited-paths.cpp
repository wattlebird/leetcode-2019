#include "util.h"

using namespace std;

class UnionFindSet {
public:
    UnionFindSet(int n = 0) {
        this -> ufs = vector<int>(n, -1);
    };

    int find(int x) {
        if (ufs[x] < 0) return x;
        else return ufs[x] = find(ufs[x]);
    };

    void join(int x, int y) {
        int ux = find(x);
        int uy = find(y);
        if (ux == uy) return;
        if (ux > uy) swap(ux, uy);
        ufs[uy] = ux;
    };
private:
    vector<int> ufs;
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        for(int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        vector<bool> rtn(queries.size());
        UnionFindSet ufs(n);
        int b = 0;
        for(vector<int>& q: queries) {
            // build union set
            int limit = q[2];
            while (b < edgeList.size() && edgeList[b][2] < limit) {
                ufs.join(edgeList[b][0], edgeList[b][1]);
                b++;
            }
            // query
            int u0 = ufs.find(q[0]), u1 = ufs.find(q[1]);
            rtn[q[3]]=u0==u1;
        }
        return rtn;
    }

};

int main() {
    vector<vector<int>> edgeList;
    vector<vector<int>> queries;
    Solution slu;

    edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    queries = {{0,1,2},{0,2,5}};
    cout << booleanVectorToString(slu.distanceLimitedPathsExist(3, edgeList, queries)) << endl;
    edgeList = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    queries = {{0,4,14},{1,4,13}};
    cout << booleanVectorToString(slu.distanceLimitedPathsExist(5, edgeList, queries)) << endl;
    return 0;
}
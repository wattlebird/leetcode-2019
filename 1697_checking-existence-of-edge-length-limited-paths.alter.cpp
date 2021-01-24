#include "util.h"
#include <queue>
#include <set>

using namespace std;

typedef struct {
    int v, w, prev;
} edge_t;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        preprocess(edgeList);
        vector<int> head(n, -1);
        vector<edge_t> edges;
        for(int i = 0; i < edgeList.size(); i++) {
            edges.push_back({.v = edgeList[i][1], .w = edgeList[i][2], .prev = head[edgeList[i][0]]});
            head[edgeList[i][0]] = edges.size() - 1;
            edges.push_back({.v = edgeList[i][0], .w = edgeList[i][2], .prev = head[edgeList[i][1]]});
            head[edgeList[i][1]] = edges.size() - 1;
        }
        
        vector<bool> rst;
        for(auto q: queries) {
            vector<bool> vis(n, false);
            queue<pair<int, int>> Q;
            int u = q[0], terminus = q[1], les = q[2];
            Q.push(pair<int, int>(u, 0));
            bool flag = false;
            while (!Q.empty()) {
                auto p = Q.front();
                Q.pop();
                u = p.first;
                int cumsum = p.second;
                if (u == terminus) {
                    flag = true;
                    rst.push_back(true);
                    break;
                }
                vis[u]=true;
                for(int e = head[u]; e != -1; e = edges[e].prev) {
                    if (edges[e].w < les && vis[edges[e].v] == false) {
                        Q.push(pair<int, int>(edges[e].v, edges[e].w + cumsum));
                    }
                }
            }
            if (!flag) rst.push_back(false);
        }
        return rst;
    }

private:
    void preprocess(vector<vector<int>>& edgeList) {
        for(vector<int>& edge : edgeList) {
            if (edge[0] > edge[1]) swap(edge[0], edge[1]);
        }
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] != b[0] ? (a[0] < b[0]) : (a[1] != b[1] ? a[1] < b[1] : a[2] < b[2]);
        });
        int b = 0, e = 1;
        while (e < edgeList.size()) {
            while (e < edgeList.size() && edgeList[b][0] == edgeList[e][0] && edgeList[b][1] == edgeList[e][1]) e++;
            if (e < edgeList.size()) {
                edgeList[++b] = edgeList[e];
            }
        }
        edgeList.erase(edgeList.begin() + b + 1, edgeList.end());
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
    cout << booleanVectorToString(slu.distanceLimitedPathsExist(3, edgeList, queries)) << endl;
    return 0;
}
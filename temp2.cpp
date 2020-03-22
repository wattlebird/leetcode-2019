#include "util.h"
#include <queue>
#include <set>

using namespace std;

typedef struct {
    int v, prev;
} edge_t;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<double> prob(n + 1, 0);
        vector<bool> visit(n+1, false);
        vector<edge_t> es;
        vector<int> head(n+1, -1);
        for(auto edge: edges) {
            es.push_back(edge_t{.v=edge[1], .prev=head[edge[0]]});
            head[edge[0]] = es.size() - 1;
            es.push_back(edge_t{.v=edge[0], .prev=head[edge[1]]});
            head[edge[1]] = es.size() - 1;
        }
        queue<int> Q;
        Q.push(1);
        prob[1]=1.0;
        while (!Q.empty() && t != 0) {
            vector<int> us;
            while (!Q.empty()) {us.push_back(Q.front()); Q.pop();}
            t--;
            for(int u: us) {
                vector<int> vs;
                int childs = 0;
                visit[u] = true;
                
                for(int e = head[u]; e != -1; e = es[e].prev) {
                    int v = es[e].v;
                    if (visit[v] != true) {
                        childs++;
                        vs.push_back(v);
                        Q.push(v);
                    }
                }
                for(int v : vs) {
                    prob[v]=  prob[u]/childs;
                    if (v == target && t == 0) return prob[v];
                }
                if (childs != 0) prob[u] = 0.0;
            }
        }
        return prob[target];
    }
};

int main() {
    vector<vector<int>> edges;

    edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    cout<<Solution().frogPosition(7, edges, 2, 4)<<endl;
    edges = {{2,1},{3,2}};
    cout<<Solution().frogPosition(3, edges, 1, 2)<<endl;
    edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    cout<<Solution().frogPosition(7, edges, 20, 6)<<endl;
    
    edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    cout<<Solution().frogPosition(7, edges, 20, 6)<<endl;
    
    edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    cout<<Solution().frogPosition(7, edges, 1, 7)<<endl;

    edges = {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}};
    cout<<Solution().frogPosition(8, edges, 7, 7)<<endl;
    return 0;

}
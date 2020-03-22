#include "util.h"

using namespace std;

typedef struct {
    int v, prev;
} edge_t;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> head(numCourses, -1), indegree(numCourses, 0);
        vector<edge_t> edges;
        queue<int> Q;
        for(vector<int> e : prerequisites) {
            edges.push_back({.v = e[0], .prev = head[e[1]]});
            head[e[1]] = edges.size() - 1;
            indegree[e[0]]++;
        }
        for(int i = 0; i < numCourses; i++) if (indegree[i] == 0) Q.push(i);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(int e = head[u]; e != -1; e = edges[e].prev) {
                if (--indegree[edges[e].v] == 0) Q.push(edges[e].v);
            }
        }
        return all_of(indegree.begin(), indegree.end(), [](int i){return i==0;});
    }
};

int main() {
    vector<vector<int>> prerequisits = {
        {0, 2},
        {1, 0},
        {2, 1}
    };
    bool rtn= Solution().canFinish(3, prerequisits);
    cout << boolToString(rtn)<< endl;
    return 0;
}
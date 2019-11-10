#include "util.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef int edge_index;
typedef int vertex_index;
typedef struct {
    edge_index prev;
    vertex_index v;
} edge;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->wordList = wordList;
        this->beginWord = beginWord;
        this->endWord = endWord;

        this->head = vector<vertex_index>(wordList.size()+1, -1);
        
        this->depth = bfs(0);
        if (this->depth == -1) return vector<vector<string>>();

        this->vis = vector<bool>(wordList.size()+1, false);
        this->S.push_back(0);
        dfs(0, 1);
        vector<vector<string>> rst;
        for(const vector<int>& itm : this->rtn) {
            vector<string> translated {beginWord};
            for(int i = 1; i < itm.size(); i++) {
                translated.push_back(wordList[itm[i]-1]);
            }
            rst.push_back(translated);
        }
        return rst;
    }
private:
    string beginWord;
    string endWord;
    vector<string> wordList;
    vector<bool> vis;
    vector<vector<int>> rtn;
    vector<int> S;
    vector<edge> edges;
    vector<vertex_index> head;
    int target = -1;
    int depth;

    int bfs(int cur) {
        unordered_map<string, int> L;
        L[beginWord] = 0;
        for (int i = 0; i != wordList.size(); i++) L[wordList[i]] = i+1;
        queue<int> Q;
        vector<int> vis(wordList.size()+1, -1);
        Q.push(cur);
        vis[cur] = 0;
        while(!Q.empty()) {
            unordered_set<int> temp;
            while(!Q.empty()) {if(target == Q.front()) return vis[target]; temp.insert(Q.front()); Q.pop();}
            for (unordered_set<int>::const_iterator i = temp.begin(); i != temp.end(); i++) {
                cur = *i;
                string curstr = cur == 0 ? beginWord : wordList[cur - 1];
                for (int s = 0; s != curstr.size(); s++) for (char a = 'a'; a <= 'z'; a++) {
                    string nxtstr = string(curstr);
                    nxtstr[s] = a;
                    if (L.count(nxtstr)) {
                        int nxt = L[nxtstr];
                        if (vis[nxt] == vis[cur] + 1 || vis[nxt] == -1) {
                            if (endWord == nxtstr) target = nxt;
                            edges.push_back(edge {head[cur], nxt});
                            head[cur] = edges.size() - 1;
                            vis[nxt] = vis[cur] + 1;
                            Q.push(nxt);
                        }
                    }
                }
                //for (size_t j = 0; j != wordList.size(); j++) {
                //    int nxt = j + 1;
//
                //    string nxtstr = wordList[j];
                //    if (diff(nxtstr, curstr) == 1 && (vis[nxt] == vis[cur] + 1 || vis[nxt] == -1)) {
                //        if (endWord == nxtstr) target = nxt;
                //        edges.push_back(edge {head[cur], nxt});
                //        head[cur] = edges.size() - 1;
                //        vis[nxt] = vis[cur] + 1;
                //        Q.push(nxt);
                //    }
                //}
            }
        }
        return -1;
    }

    void dfs(int cur, int cd) {
        for(edge_index e = head[cur]; e != -1; e = edges[e].prev) {
            int i = edges[e].v;
            if (!this->vis[i]) {
                this->vis[i] = true;
                this->S.push_back(i);
                if (i == target) {
                    this->rtn.push_back(this->S);
                    this->S.pop_back();
                    this->vis[i] = false;
                } else {
                    if (cd < depth) {
                        dfs(i, cd + 1);
                    }
                    this->S.pop_back();
                    this->vis[i] = false;
                }
            }
        }
    }

    int diff(string a, string b) {
        int rtn = 0;
        for (int i=0; i!=a.size(); i++) {if (a[i] != b[i]) rtn++; if (rtn > 1) break;}
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        string beginWord = line;
        
        getline(cin, line);
        trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        string endWord = line;

        getline(cin, line);
        vector<string> wordvec = stringToStringVector(line);
        
        vector<vector<string>> rtn = Solution().findLadders(beginWord, endWord, wordvec);

        for(const vector<string>& itm : rtn) {
            cout << stringVectorToString(itm) << endl;
        }
    }
    return 0;
}
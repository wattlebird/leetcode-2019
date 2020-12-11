#include "util.h"
#include <map>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        rtn = 0;
        this-> arr = arr;
        for(int i = 0; i < arr.size(); i++) {
            dfs(i, 0, 0);
        }
        return rtn;
    }

    void dfs(unsigned int idx, unsigned int vis, unsigned int mask) {
        unsigned int nvis = (vis | (1<<idx));
        if (lut.count(nvis) > 0) return;
        unsigned int cur = converter(arr[idx]);
        if (cur == 0 || (cur & mask) > 0) {
            lut[nvis] = 0;
            return;
        } else {
            lut[nvis] = lut[vis] + arr[idx].size();
            rtn = max(rtn, lut[nvis]);
            for(int i = 0; i < arr.size(); i++) if ((nvis & (1 << i)) == 0) dfs(i, nvis, cur | mask);
        }
    }

    unsigned int converter(string str) {
        unsigned int rtn = 0;
        for(char c: str) {
            unsigned int t = (1 << ix(c));
            if ((rtn & t) == 0) rtn |= t;
            else return 0;
        }
        return rtn;
    }
    
    int ix(char c) {return c-'a';}

    vector<string> arr;
    map<unsigned int, int> lut;
    int rtn;
};

int main() {
    vector<string> arr;
    Solution slu;
    arr = {"un","iq","ue"};
    cout << slu.maxLength(arr) << endl;
    arr = {"cha","r","act","ers"};
    cout << slu.maxLength(arr) << endl;
    arr = {"abcdefghijklmnopqrstuvwxyz"};
    cout << slu.maxLength(arr) << endl;
    return 0;
}
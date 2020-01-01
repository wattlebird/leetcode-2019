#include "util.h"

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int G[128] = {0};
        for(char c: S) G[c]++;
        auto comp = [G](char c1, char c2) {return G[c1] == G[c2] ? c1 > c2 : G[c1] > G[c2];};
        sort(S.begin(), S.end(), comp);
        if (S[0] == S[(S.size() -1)/2 + 1]) return "";
        else {
            string T;
            for(int i = 0, j = (S.size() -1) / 2 + 1; i<=(S.size() -1)/2; i++, j++) {
                T += S[i];
                if (j < S.size()) T+=S[j];
            }
            return T;
        }
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        
        string ret = Solution().reorganizeString(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
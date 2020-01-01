#include "util.h"

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int cnt[128] = {0};
        for(char c: S) cnt[c]++;
        container.clear();
        size = 0;
        for(char c = 'a'; c <= 'z'; c++) if (cnt[c] != 0) container.push_back(pair<char, int>(c, cnt[c]));
        heapify();
        string T = "";
        while (size != 0) {
            if (size == 1) {
                if (container[0].second == 1) {
                    T += container[0].first;
                    break;
                } else {
                    return "";
                }
            }
            int i = 0, j = container[1].second < container[2].second ? 2 : 1;
            if (T.size() != 0 && T.back() == container[i].first) {
                T += container[j].first; T += container[i].first;
            } else {
                T += container[i].first; T += container[j].first;
            }
            if (--container[j].second == 0) {
                size--;
                swap(container[j], container[size]);
            }
            sift_down(j);
            if (--container[i].second == 0) {
                size--;
                swap(container[i], container[size]);
            }
            sift_down(i);
        }
        return T;
    }
private:
    vector<pair<char, int>> container;
    size_t size;
    void heapify() {
        size = container.size();
        int m = size / 2 - 1;
        while (m >= 0) {
            sift_down(m--);
        }
    }
    void sift_down(int i) {
        while (i < size) {
            size_t j1 = 1 + (i<<1), j2 = 2 + (i<<1), j;
            if (j1 >= size) break;
            else if (j2 >= size) j = j1;
            else j = container[j1].second < container[j2].second ? j2 : j1;
            if (container[j].second > container[i].second) {
                swap(container[i], container[j]);
                i = j;
            } else break;
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
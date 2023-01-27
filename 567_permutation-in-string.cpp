#include "util.h"
#include <set>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> lut(128, 0);
        set<char> xs;
        for(int i = 0; i < s1.size(); i++) {
            xs.insert(s1[i]);
            lut[s1[i]]++;
        }
        for(int i = 0; i < s1.size(); i++) {
            if (xs.count(s2[i]) != 0) {
                lut[s2[i]]--;
            }
        }
        if (isValid(lut, xs)) return true;
        for(int i = 0, j = s1.size(); j < s2.size(); i++, j++) {
            if (xs.count(s2[j]) != 0) {
                lut[s2[j]]--;
            }
            if (xs.count(s2[i]) != 0) {
                lut[s2[i]]++;
            }
            if (isValid(lut, xs)) return true;
        }
        return false;
    }

    bool isValid(vector<int>& lut, set<char>& xs) {
        for(set<char>::const_iterator itr = xs.begin(); itr != xs.end(); itr++) {
            if (lut[*itr] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution slu;
    cout << slu.checkInclusion("ab", "eidbaooo") << endl;
    cout << slu.checkInclusion("hello", "ooolleoooleh") << endl;
    cout << slu.checkInclusion("adc", "dcda") << endl;
    cout << slu.checkInclusion("dinitrophenylhydrazine", "dimethylhydrazine") << endl;
    return 0;
}
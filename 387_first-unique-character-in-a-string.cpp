#include "util.h"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[128];
        fill(arr, arr+128, 0);
         for(int mark = 0; mark < s.size(); mark++) {
            char c = s[mark];
            if (arr[c] == 0) arr[c] = mark + 1;
            else arr[c] = -1;
        }
        int idx = 'a';
        for(char c = 'a'; c <= 'z'; c++) {
            if (arr[c] > 0) {
                if (arr[idx] <= 0) idx = c;
                else if (arr[idx] > arr[c]) idx = c;
            }
        }
        return arr[idx] <= 0 ? -1 : arr[idx] - 1;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().firstUniqChar(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
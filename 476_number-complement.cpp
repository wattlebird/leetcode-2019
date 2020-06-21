#include "util.h"

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int shift = 0;
        int mask = 0xffffffff;
        while ((0x80000000 & num) == 0x0) {
            num<<=1;
            mask<<= 1;
            shift++;
        }
        int rtn = mask ^ num;
        return rtn >>= shift;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        int ret = Solution().findComplement(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
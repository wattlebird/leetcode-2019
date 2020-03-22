#include "util.h"

using namespace std;

class Solution {
public:
    void cycleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 2; i++) {
            int pos = i, cache = nums[i];
            for(int j = i+1; j < nums.size(); j++) if (nums[j] < cache) pos++;
            while(pos != i && nums[pos] == cache) pos++;
            if (pos == i) continue;
            swap(nums[pos], cache);
            while (true) {
                pos = i;
                for(int j = i+1; j < nums.size(); j++) if (nums[j] < cache) pos++;
                while(pos != i && nums[pos] == cache) pos++;
                swap(nums[pos], cache);
                if (pos == i) break;
            }
        }
        return;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().cycleSort(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
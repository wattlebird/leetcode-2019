#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if (numbers[i] + numbers[j] == target) {
                return vector<int> {i, j};
            } else if (numbers[i] + numbers[j] < target) i++;
            else j--;
        }
        return vector<int>();
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> numbers = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(numbers, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        // Continue processing the string until its length is less than or equal to k
        while(n > k) {
            int step = 1;
            int sum = 0;
            string result = "";
            for(char dig : s){
                int dig_int = dig - '0';
                sum += dig_int;
                if (step >= k) {
                    step = 1;
                    result += to_string(sum);
                    sum = 0;
                }
                else step++;
            }
            if (step > 1) result += to_string(sum);
            n = result.length();
            s = result;
        }

        return s;
    }
};

int main() {
    Solution solution;

    const string firstResult = solution.digitSum("11111222223", 3);
    const string secondResult = solution.digitSum("00000000", 3);

    cout << "Example 1 result: " << firstResult << '\n';
    cout << "Example 1 expected: 135\n";
    cout << "Example 2 result: " << secondResult << '\n';
    cout << "Example 2 expected: 000\n";

    assert(firstResult == "135");
    assert(secondResult == "000");
}
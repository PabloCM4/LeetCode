#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool b_found = false;
        for ( char letter : s )
        {
            if (!b_found) {
                if ( letter == 'b'  ) b_found = true;
            }
            else {
                if ( letter == 'a' ) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    const string firstInput = "aaabbb";
    const bool firstResult = solution.checkString(firstInput);
    const bool firstExpected = true;

    const string secondInput = "abab";
    const bool secondResult = solution.checkString(secondInput);
    const bool secondExpected = false;

    const string thirdInput = "bbb";
    const bool thirdResult = solution.checkString(thirdInput);
    const bool thirdExpected = true;

    cout << "Example 1: input = \"" << firstInput
         << "\", result = " << boolalpha << firstResult
         << ", expected = " << firstExpected << '\n';
    cout << "Example 2: input = \"" << secondInput
         << "\", result = " << secondResult
         << ", expected = " << secondExpected << '\n';
    cout << "Example 3: input = \"" << thirdInput
         << "\", result = " << thirdResult
         << ", expected = " << thirdExpected << '\n';

    return 0;
}
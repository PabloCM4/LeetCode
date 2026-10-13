#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long result = 0;

        // Sort by absolute value biggest to smallest
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        // Add the biggest and substract the smallest
        int positiveCount = (nums.size() + 1) / 2;
        for(int i=0; i < nums.size(); i++) {
            long long square = 1LL * nums[i] * nums[i];
            if (i < positiveCount) {
                result += square;
            }
            else {
                result -= square;
            }
        }

        return result;
    }
};

int main() {
    // Test Case 1
    vector<int> nums1 = {2, 1, 3};
    Solution sol;
    cout << "Test 1: " << sol.maxAlternatingSum(nums1) << " (Expected 12)" << endl;

    // Test Case 2
    vector<int> nums2 = {-3, -1, -2, 1, 3, 2};
    cout << "Test 2: " << sol.maxAlternatingSum(nums2) << " (Expected 16)" << endl;

    return 0;
}
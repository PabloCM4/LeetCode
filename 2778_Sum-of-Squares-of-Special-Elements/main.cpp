#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) sum += nums[i-1]*nums[i-1];
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // Example 1: nums = [1,2,3,4] → expected output: 21
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Example 1: " << solution.sumOfSquares(nums1) << " (expected: 21)" << endl;

    // Example 2: nums = [2,7,1,19,18,3] → expected output: 92
    vector<int> nums2 = {2, 7, 1, 19, 18, 3};
    cout << "Example 2: " << solution.sumOfSquares(nums2) << " (expected: 63)" << endl;

    return 0;
}

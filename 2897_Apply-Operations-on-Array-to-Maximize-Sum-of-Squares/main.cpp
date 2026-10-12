#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        vector<int> bit_count(30, 0);
        long long result = 0;

        for (int number: nums) {
            for (int bit = 0; bit < 30; bit++) {
                if (number & (1LL << bit)) {
                    bit_count[bit]++;
                } // if
            } // for
        } // for

        for (int i = 0; i < k; i++) {
            long long current = 0;

            for (int bit = 0; bit < 30; bit++) {
                if (bit_count[bit] > 0) {
                    current |= (1LL << bit);
                    bit_count[bit]--;
                } // if
            } // for

            result = (result + current * current) % 1000000007LL;
        } // for

        return static_cast<int>(result);
    } // int maxSum
}; // class


int main() {
    // Test Case 1
    vector<int> nums1 = {2, 6, 5, 8};
    int k1 = 2;
    Solution sol;
    cout << "Test 1: " << sol.maxSum(nums1, k1) << " (Expected 261)" << endl;

    // Test Case 2
    vector<int> nums2 = {4, 5, 4, 7};
    int k2 = 3;
    cout << "Test 2: " << sol.maxSum(nums2, k2) << " (Expected 261)" << endl;

    return 0;
}
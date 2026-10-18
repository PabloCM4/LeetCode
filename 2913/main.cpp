#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int left = 0; left < n; ++left) {
            unordered_map<int, int> freq;

            for (int right = left; right < n; ++right) {
                freq[nums[right]]++;
                int distinct = freq.size();
                totalSum += distinct * distinct;
            }
        }
        return totalSum;
    }
};

int main() {
    Solution sol;

    vector<int> example1 = {1, 2, 1};
    vector<int> example2 = {1, 1};

    cout << "Example 1:" << endl;
    cout << "Input: nums = [1,2,1]" << endl;
    cout << "Output: " << sol.sumCounts(example1) << " (15)" <<endl;

    cout << "Example 2:" << endl;
    cout << "Input: nums = [1,1]" << endl;
    cout << "Output: " << sol.sumCounts(example2) << " (3)" <<endl;

    return 0;
}
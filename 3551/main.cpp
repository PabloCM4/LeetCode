#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int const nums_size = nums.size();
        int swaps = 0;
        vector<int> sorted_nums = nums;
        unordered_map<int, int> destination;
        vector<bool> visited(nums_size, false);

        // Sort the numbers based on the sum of their digits
        sort(sorted_nums.begin(), sorted_nums.end(), [](int a, int b) {
            int sum_a = 0, sum_b = 0;
            int temp_a = a, temp_b = b;
            while (temp_a > 0) {
                sum_a += temp_a % 10;
                temp_a /= 10;
            }
            while (temp_b > 0) {
                sum_b += temp_b % 10;
                temp_b /= 10;
            }
            if (sum_a == sum_b) {
                return a < b; // If sums are equal, sort by value in ascending order
            }
            return sum_a < sum_b; // Sort in ascending order
        });
        
        // Create a mapping from the original indices to the sorted indices
        for (int i = 0; i < nums_size; i++) {
            destination[sorted_nums[i]] = i;
        }

        // Calculate the minimum number of swaps needed
        for (int i = 0; i < nums_size; i++) {
            if (visited[i] || destination[nums[i]] == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = destination[nums[j]];
                cycle_size++;
            }

            if (cycle_size > 0) {
                swaps += cycle_size - 1;
            }
        }

        return swaps;

    }
};
/*
    // Code to study. I like it, sorting the using the vector of pairs. Then using swap().
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            arr[i] = {sum, nums[i]};
        }
        
        sort(arr.begin(), arr.end());
        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == arr[i].second) continue;
            int wanted = arr[i].second;
            int j = pos[wanted];
            swap(nums[i], nums[j]);
            pos[nums[j]] = j;
            pos[nums[i]] = i;
            swaps++;
        }
        return swaps;
    }
};*/

int main() {
    Solution solution;

    vector<vector<int>> test_cases = {
        {37, 100},
        {22, 14, 33, 7},
        {18, 43, 34, 16}
    };

    vector<int> expected_outputs = {1, 0, 2};

    for (size_t i = 0; i < test_cases.size(); i++) {
        cout << "Test case " << i + 1 << '\n';
        cout << "Expected output: " << expected_outputs[i] << '\n';
        cout << "Solution output: " << solution.minSwaps(test_cases[i]) << "\n\n";
    }

    return 0;
}
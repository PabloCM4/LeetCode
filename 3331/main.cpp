#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int parent_size = parent.size();
        vector<int> new_parent(parent_size,-1);

        // Very inneficient way to find the new parent for each node
        // This is close to O(n^2) in the worst case, but it works for small inputs
        for(int x = 1; x < parent_size; x++)
        {
            int ancestor = parent[x];
            while (ancestor != -1)
            {
                if (s[ancestor] == s[x]) break;
                ancestor = parent[ancestor];
            }
            if (ancestor == -1)
            {
                new_parent[x] = parent[x];
            }
            else
            {
                new_parent[x] = ancestor;
            }
        }
        
        // Very inneficient way to count the number of nodes in each subtree
        // This is O(n^2) in the worst case, but it works for small inputs
        vector<int> subcount(parent_size,1);
        for (int x = 1; x < parent_size; x++)
        {
            int ancestor = new_parent[x];
            while (ancestor != -1)
            {
                subcount[ancestor]++;
                ancestor = new_parent[ancestor];
            }
        }

        return subcount;
    }
};

int main() {
    Solution solution;

    vector<int> parent1 = {-1, 0, 0, 1, 1, 1};
    string s1 = "abaabc";
    vector<int> result1 = solution.findSubtreeSizes(parent1, s1);
    vector<int> expected1 = {6, 3, 1, 1, 1, 1};

    cout << "Example 1 - Result: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << result1[i];
    }
    cout << "], Expected: [";
    for (size_t i = 0; i < expected1.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << expected1[i];
    }
    cout << "]" << endl;

    vector<int> parent2 = {-1, 0, 4, 0, 1};
    string s2 = "abbba";
    vector<int> result2 = solution.findSubtreeSizes(parent2, s2);
    vector<int> expected2 = {5, 2, 1, 1, 1};

    cout << "Example 2 - Result: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << result2[i];
    }
    cout << "], Expected: [";
    for (size_t i = 0; i < expected2.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << expected2[i];
    }
    cout << "]" << endl;

    return 0;
}
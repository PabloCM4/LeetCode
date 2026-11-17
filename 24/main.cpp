#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // End early if list is too short
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        } 

        // Three pointers needed for the swap
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *prev = nullptr;

        //First iteration to handle head and no previous node
        head = head->next;
        first->next = second->next;
        second->next = first;
        prev = first;
        first = first->next;

        // Main loop to swap nodes
        while(first != nullptr)
        {   
            // Preparation
            second = first->next;
            if (second == nullptr) break;

            // Swap
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Update for next iteration
            prev = first;
            first = first->next;
        }
        
        return head;
    }
};

ListNode* buildList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        ListNode* node = new ListNode(value);
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return head;
}

std::string formatList(ListNode* head) {
    std::ostringstream output;
    output << '[';

    bool first = true;
    while (head != nullptr) {
        if (!first) {
            output << ',';
        }
        output << head->val;
        first = false;
        head = head->next;
    }

    output << ']';
    return output.str();
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void testCase(const std::string& input,
              const std::vector<int>& values,
              const std::string& expected) {
    ListNode* resultHead = Solution().swapPairs(buildList(values));
    std::string result = formatList(resultHead);

    std::cout << "Input: " << input << '\n';
    std::cout << "Output: " << result << '\n';
    std::cout << "Expected: " << expected << '\n';
    std::cout << (result == expected ? "PASS" : "FAIL") << "\n\n";

    freeList(resultHead);
}

int main() {
    testCase("head = [1,2,3,4]", {1, 2, 3, 4}, "[2,1,4,3]");
    testCase("head = []", {}, "[]");
    testCase("head = [1]", {1}, "[1]");
    testCase("head = [1,2,3]", {1, 2, 3}, "[2,1,3]");
    return 0;
}
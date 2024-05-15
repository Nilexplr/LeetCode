#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNodes(ListNode* head) {
    if (head->next == nullptr)
        return head;
    head->next = removeNodes((head->next));
    if (head->val < head->next->val)
        return head->next;
    return head;
}
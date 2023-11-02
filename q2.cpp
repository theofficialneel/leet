#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode* a = new ListNode(0);
    ListNode* curr = a;
    while (l1 != NULL || l2 != NULL || c != 0) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = c + x + y;
        c = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return a->next;
}
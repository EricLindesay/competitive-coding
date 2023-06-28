#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *out = new ListNode();
        ListNode *currentNode = out;

        int carry = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            currentNode->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;

            l1 = l1->next;
            l2 = l2->next;

            if (l1 != nullptr || l2 != nullptr || carry)
            {
                ListNode *node = new ListNode();
                currentNode->next = node;
                currentNode = node;
            }
        }

        while (l1 != nullptr)
        {
            currentNode->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;

            l1 = l1->next;
            if (l1 != nullptr || carry)
            { // if this was the last node of the program, don't add it
                ListNode *node = new ListNode();
                currentNode->next = node;
                currentNode = node;
            }
        }

        while (l2 != nullptr)
        {
            currentNode->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;

            l2 = l2->next;
            if (l2 != nullptr || carry)
            { // if this was the last node of the program, don't add it
                ListNode *node = new ListNode();
                currentNode->next = node;
                currentNode = node;
            }
        }

        if (carry)
        {
            currentNode->val = carry;
        }
        return out;
    }
};

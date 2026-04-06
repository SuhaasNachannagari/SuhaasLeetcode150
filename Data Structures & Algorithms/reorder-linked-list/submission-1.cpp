/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode* prev = nullptr;
        ListNode* current = slow->next;

        while(current) {
            ListNode* after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }        

        slow->next = nullptr;

        ListNode* currentOne = head;
        ListNode* currentTwo = prev;

        while (currentTwo) {
            ListNode* temp1 = currentOne ->next;
            ListNode* temp2= currentTwo->next;

            currentOne->next = currentTwo;
            currentTwo ->next = temp1;
            currentOne = temp1;
            currentTwo = temp2;
        }

    }
};

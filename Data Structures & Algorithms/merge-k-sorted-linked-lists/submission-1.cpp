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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        priority_queue<pair<int, ListNode*>, 
                       vector<pair<int, ListNode*>>, 
                       greater<pair<int, ListNode*>>> minHeap;
        // Proccess every node in every list, linear time
        for (auto head : lists) {
            if (head) {
                minHeap.push({head->val, head});
            }
        }
        
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top().second;
            current->next = top;
            minHeap.pop();
            current = current->next;

            if (top->next) {
                minHeap.push({top->next->val, top->next});
            }
        }

        return dummy.next;



    }
};

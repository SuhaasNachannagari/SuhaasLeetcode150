/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> orgToDup;

        Node* current = head;
        while (current) {
            Node* dup = new Node(current->val);
            orgToDup[current] = dup;
            current = current->next;
        }

        current = head;
        while (current) {
            Node* next = current->next;
            Node* random = current->random;
            Node* copy = orgToDup[current];

            copy->next = orgToDup[next];
            copy->random = orgToDup[random];
            current = current->next;
        }

        return orgToDup[head];

    }
};

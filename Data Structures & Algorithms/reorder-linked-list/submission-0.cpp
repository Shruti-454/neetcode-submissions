class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // find middle of linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // merge both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {

            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};
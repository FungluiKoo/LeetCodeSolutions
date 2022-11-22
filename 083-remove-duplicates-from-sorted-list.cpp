struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto result = head;
        while(head){
            while(head->next && head->val==head->next->val){
                auto tmp = head->next;
                head->next = tmp->next;
                delete tmp;
            }
            head = head->next;
        }
        return result;
    }
};
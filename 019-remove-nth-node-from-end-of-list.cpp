struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto turtle = head;
        auto rabbit = head;
        for(int i=0; i<n; ++i){
            rabbit = rabbit->next;
        }
        if(rabbit==nullptr){
            auto tmp = head->next;
            delete head;
            return tmp;
        }
        while(rabbit->next){
            turtle = turtle->next;
            rabbit = rabbit->next;
        }
        auto tmp = turtle->next;
        turtle->next = tmp->next;
        delete tmp;
        return head;
    }
};
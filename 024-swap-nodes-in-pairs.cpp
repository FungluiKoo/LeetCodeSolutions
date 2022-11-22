struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){return head;}
        auto result = head->next;
        while(true){
            auto tmp = head->next->next;
            head->next->next = head;
            if(tmp && tmp->next){
                head->next = tmp->next;
                head = tmp;
            }else{
                head->next = tmp;
                break;
            }
        }
        return result;
    }
};
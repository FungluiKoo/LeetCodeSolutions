struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){return head;}
        auto result = head;
        auto even_head = head->next;
        while(true){
            auto tmp = head->next->next;
            if(tmp && tmp->next){
                head->next->next = tmp->next;
                head->next = tmp;
                head = tmp;
            }else{
                head->next->next = nullptr;
                if(tmp){
                    head->next = tmp;
                    tmp->next = even_head;
                }else{
                    head->next = even_head;
                }
                break;
            }
        }
        return result;
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){return list2;}
        if(list2==nullptr){return list1;}
        ListNode *result, *prev;
        if(list1->val < list2->val){
            result = prev = list1;
            list1 = list1->next;
        }else{
            result = prev = list2;
            list2 = list2->next;
        }
        while(list1 && list2){
            if(list1->val < list2->val){
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            }else{
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
        }
        prev->next = list1 ? list1 : list2;
        return result;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int len(ListNode* head){
        int n = 0;
        while(head){
            ++n;
            head = head->next;
        }
        return n;
    }

    ListNode* next(ListNode* curr, int x){
        while(curr && x){
            curr = curr->next;
            --x;
        }
        return curr;
    }

    ListNode* mergeTwoSortedLists(ListNode* prev, ListNode* list1, ListNode* list2) { // modified from LeetCode 021
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
        while(prev->next){prev = prev->next;}
        return prev;
    }
public:
    ListNode* sortList(ListNode* head) {
        auto n = len(head);
        if(n<2){return head;}
        ListNode dummy;
        dummy.next = head;
        for(int group_size = 1; group_size<n; group_size<<=1){
            ListNode *prev = &dummy, *list1 = dummy.next;
            while(list1){
                auto list1_last = next(list1, group_size-1);
                auto list2 = next(list1_last, 1);
                if(list1_last){list1_last->next = nullptr;}
                auto list2_last = next(list2, group_size-1);
                auto next_list1 = next(list2_last, 1);
                if(list2_last){list2_last->next = nullptr;}
                prev = mergeTwoSortedLists(prev, list1, list2);
                list1 = next_list1;
            }
        }
        return dummy.next;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reverseList(ListNode* head) { // LeetCode 206
        ListNode* prev = nullptr;
        while(head){
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr){return true;}
        auto slow = head;
        auto fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right_head = reverseList(slow);
        while(head && right_head){
            if(head->val!=right_head->val){return false;}
            head = head->next;
            right_head = right_head->next;
        }
        return true;
    }
};
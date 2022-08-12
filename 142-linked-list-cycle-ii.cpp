using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        do{
            if(fast==nullptr || fast->next==nullptr){return nullptr;}
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);
        fast = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
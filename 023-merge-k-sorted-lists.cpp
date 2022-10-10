#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Comp {
    constexpr bool operator()(ListNode *a, ListNode *b)const{
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> heads;
        for(auto list: lists){
            if(list){heads.push(list);}
        }
        if(heads.empty()){return nullptr;}
        ListNode *head = heads.top();
        heads.pop();
        if(head->next){
            heads.push(head->next);
        }
        auto prev = head;
        while(!heads.empty()){
            auto curr = heads.top();
            prev->next = curr;
            heads.pop();
            if(curr->next){
                heads.push(curr->next);
            }
            prev = curr;
        }
        return head;
    }
};
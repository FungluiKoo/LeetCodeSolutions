#include <random>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* head;
    mt19937 gen;
    std::uniform_int_distribution<> dis;

public:
    Solution(ListNode* head) {
        this->head = head;
        int n = 0;
        while(head){
            ++n;
            head = head->next;
        }
        random_device rd;
        gen.seed(rd());
        dis.param(uniform_int_distribution<>::param_type{0,n-1});
    }
    
    int getRandom() {
        int x = dis(gen);
        auto curr = head;
        while(x--){
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
Your Solution object will be instantiated and called as such:
Solution* obj = new Solution(head);
int param_1 = obj->getRandom();
 */
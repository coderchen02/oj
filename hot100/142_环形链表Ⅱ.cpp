// 3.2 21点05分
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            //快慢指针相遇，此时从head和相遇点，同时查找直至相遇就是环的入口
            if(slow==fast){
                ListNode* index1=fast;
                ListNode* index2=head;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};
// 2026.2.3 17点21分
class Solution {
public:
    ListNode* mergeList(ListNode* left,ListNode* right)
    {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(left&&right){
            if(left->val<right->val){
                tail->next=left;
                left=left->next;
            }
            else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        if(left) 
            tail->next=left;
        if(right)
            tail->next=right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
       if(!head||!head->next) return head; 
       ListNode* slow=head;
       ListNode* fast=head->next;
       while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* second=slow->next;
       slow->next=NULL;
       ListNode* first=head;
       first=sortList(first);
       second=sortList(second);
       return mergeList(first,second);
    }
};
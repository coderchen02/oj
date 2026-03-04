// 3.4 21点47分
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* header =new ListNode(0);
        header->next=head;
        ListNode* fast=header;
        ListNode* slow=header;
        int cnt=n+1;
        while(cnt--)
            fast=fast->next;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        //此时slow指针指向的就是要删除的节点的前一个结点
        ListNode* tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        tmp=NULL;
        return header->next;//这里返回的是header的下一个节点，因为有可能删除的是第一个有效节点既head
    }
};
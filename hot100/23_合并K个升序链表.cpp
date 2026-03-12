/**
3.12 20点21分
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            vector<ListNode*>tempList;
            for(int i=0;i<lists.size();i+=2){
                ListNode* l1=lists[i];
                ListNode* l2=NULL;
                if(i+1<lists.size())
                    l2=lists[i+1];
               tempList.push_back(mergeTwoList(l1,l2));
            }
            lists=tempList;
        }
        return lists[0];
    }
    ListNode* mergeTwoList(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        while(list1&&list2){
            if(list1->val<=list2->val){
                tail->next=list1;
                list1=list1->next;
            }else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(list1)
            tail->next=list1;
        else if(list2)
            tail->next=list2;
        return dummy->next;
    }
};
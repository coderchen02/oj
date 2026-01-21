// 2026.1.21 21点54分
//法一、哈希做法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        unordered_set<ListNode*> st;
        while(head){
            if(st.find(head)!=st.end()) return true;//判断这个指针有没有出现过
            st.insert(head);
            head=head->next;
        }
        return false;
    }
};
//法二、快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //要访问 A->B，必须先保证 A != NULL，否则就会触发「空指针访问」错误；`z
        //所以fast!=NULL保证了fast->next访问安全性
        //fast->next!=NULL保证了fast->next->next访问的安全性
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，说明有环
            if (slow == fast) return true;
        }
        return false;
    }
};
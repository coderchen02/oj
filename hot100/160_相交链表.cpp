/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 2026.1.20 20点17分
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //方法一、双指针法
        /*
        ListNode* curA=headA;
        ListNode* curB=headB;
        int lenA=0,lenB=0;
        //计算A链表的长度
        while(curA!=NULL){
            lenA++;  //A链表节点个数加一
            curA=curA->next;
        } 
        //计算B链表的长度
        while(curB!=NULL){
            lenB++;
            curB=curB->next;
        }
        //我们始终让A链表是较长的一个
        if(lenB>lenA){
            swap(lenA,lenB);
            swap(headA,headB);
        }
        //此时A为长链，B为短链 计算差值
        int gap=lenA-lenB;
        //此时让两个链表按照末端对齐 从第一个两个都有值的位置开始遍历
        //请注意此题的一个坑，链表相交不是值相等，而是指针相等
        curA=headA;
        curB=headB;
        while(gap--)
            curA=curA->next;
        while(curA!=NULL||curB!=NULL){
            if(curA==curB)
                return curA;
            curA=curA->next;
            curB=curB->next;
        }
        return NULL; */
        //方法2 哈希法
        //使用一个hashset  遍历一个链表，hashset中存放其所有指针， 遍历另一个链表，去hashset中找相同指针
        //时间复杂度O(m + n)    空间复杂度O(m) 或 O(n)
        std::unordered_set<ListNode*> set;
        ListNode* cur_a=headA;
        while(cur_a)
        {
            set.insert(cur_a);
            cur_a=cur_a->next;
        }
        ListNode* cur_b=headB;
        while(cur_b)
        {
            if(set.find(cur_b)!=set.end())//找到了
                return cur_b;
            cur_b=cur_b->next;
        }
        return NULL;
    }
};
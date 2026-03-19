// 3.19 23点15分
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 1. 特判：节点数少于 2 个直接返回
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; // prev 指向要交换的两个节点的前驱

        while (prev->next && prev->next->next) {
            ListNode* node1 = prev->next;
            ListNode* node2 = prev->next->next;

        
            // 1. 让 node1 指向下一组的开头（防止断链）
            node1->next = node2->next;
            // 2. 让 node2 指向 node1（完成组内翻转）
            node2->next = node1;
            // 3. 让 prev 指向 node2（把上一组和这一组连起来）
            prev->next = node2;

            // --- 移动指针 ---
            // 此时 node1 已经变成了这一组的末尾，所以 prev 跳到 node1
            prev = node1;
        }

        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};
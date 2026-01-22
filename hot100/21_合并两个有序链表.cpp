//2026.1.22 15点07分
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. 处理边界：两个链表都为空，直接返回空
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        // 2. 处理单链表为空的情况
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        // 3. 初始化头节点（解决空指针访问问题）
        ListNode* list = nullptr; // 最终返回的头节点
        ListNode* tail = nullptr; // 尾指针，用于拼接节点

        // 4. 添加第一个节点（确定头节点）
        if (list1->val > list2->val) {
            list = list2;    // 头节点指向更小的节点
            tail = list2;    // 尾指针跟进
            list2 = list2->next; // 移动list2指针
        } else {
            list = list1;
            tail = list1;
            list1 = list1->next;
        }

        // 5. 遍历两个链表（都非空时才循环，避免空指针）
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                tail->next = list2; // 拼接list2节点
                list2 = list2->next; // 移动list2
            } else {
                tail->next = list1; // 拼接list1节点
                list1 = list1->next; // 移动list1
            }
            tail = tail->next; // 尾指针跟进
        }

        // 6. 处理剩余节点（其中一个链表已空，直接拼接）
        if (list1 != nullptr) {
            tail->next = list1;
        }
        if (list2 != nullptr) {
            tail->next = list2;
        }

        // 7. 返回合并后的头节点
        return list;
    }
};
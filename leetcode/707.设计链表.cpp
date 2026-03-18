// 3.18 21点06分
class MyLinkedList {
public:
    //定义链表节点结构体
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){}
    };
    MyLinkedList() {
        _dummyHead=new ListNode(0);
        _size=0;
    }
    
    int get(int index) {
        if(index>(_size-1)||index<0)
            return -1;
        ListNode* cur=_dummyHead->next;
        while(index--)
            cur=cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* tmp=new ListNode(val);
        tmp->next=_dummyHead->next;
        _dummyHead->next=tmp;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode*tmp=new ListNode(val);
        tmp->next=nullptr;
        ListNode* cur=_dummyHead;
        while(cur->next!=nullptr)
            cur=cur->next;
        cur->next=tmp;
        _size++;

    }
    
    void addAtIndex(int index, int val) {
        if(index>_size) return ;
        if(index<0) index=0;
        ListNode* tmp=new ListNode(val);
        ListNode* cur=_dummyHead;
        while(index){
            cur=cur->next;
            index--;
        }
        tmp->next=cur->next;
        cur->next=tmp;
        _size++;
    }
    
    void deleteAtIndex(int index) {
       if(index>=_size||index<0)
            return ;
        ListNode* cur=_dummyHead;
        while(index--)
            cur=cur->next;
        ListNode*tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        tmp==nullptr;
        _size--;
    }
private:
    int _size;
    ListNode* _dummyHead;
};

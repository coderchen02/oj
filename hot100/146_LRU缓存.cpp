// 3.4 20点30分
class node{
public:
    node* next;
    node* pre;
    int key;
    int value;
    node(int k,int v){
        key=k;
        value=v;
        next=NULL;
        pre=NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(u_map.count(key)){
            remove(u_map[key]);//从哈希表中删除这个元素
            headinsert(u_map[key]);//移动这个节点到最左端，也就是最新使用的一端
            return u_map[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(u_map.count(key)){
            remove(u_map[key]);
            delete u_map[key];
            u_map[key]=NULL;
        }
        node* tmp=new node(key,value);
        headinsert(tmp);
        u_map[key]=tmp;
        if(u_map.size()>cap){
            node* todel=tail->pre;
            remove(todel);
            u_map.erase(todel->key);
            delete todel;
        }
    }
    void remove(node* tmp){
        node* tmp_pre=tmp->pre;
        node* tmp_nxt=tmp->next;
        tmp_pre->next=tmp_nxt;
        tmp_nxt->pre=tmp_pre;
    }
    void headinsert(node* tmp){//从头部插入
        node* nxt=head->next;
        head->next=tmp;
        tmp->pre=head;
        tmp->next=nxt;
        nxt->pre=tmp;
    }
private:
    int cap;
    node* head,*tail;
    unordered_map<int,node*> u_map;//用来存储节点和节点的地址 满足O（1）时间复杂度的存取
};


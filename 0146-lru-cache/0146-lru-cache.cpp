
class Node{
    
    public:
     int key;
     int val;
     Node* prev;
     Node* next;
    Node(int k , int v){
        this->key = k;
        this->val = v;
        prev = next = nullptr;
    }
};

class DoublyList{
public:

  Node* head;
  Node* tail;

  DoublyList(){
    head = new Node(-1 , -1);
    tail  = new Node(-1 , -1);

    head->next = tail;
    tail->prev = head;
  }

   void addFront(Node* node){

    Node* temp = head->next;

    head->next= node;
    node->prev = head;
    node->next = temp;
    temp->prev = node;

   }
   void remove(Node* node){
    Node* p = node->prev;
    Node* n = node->next;
    p->next = n;
    n->prev = p;
   }
   Node* getLRU(){
    return tail->prev;
   }
};

class LRUCache {
public:     
    int cap;
    unordered_map<int , Node*>mp;
    DoublyList* dll = new DoublyList();


    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node = mp[key];
        dll->remove(node);
        dll->addFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            dll->remove(node);
            node->val = value;
            dll->addFront(node);
            return ;
        }
        if(mp.size()==cap){
            Node* lru = dll->getLRU();
            mp.erase(lru->key);
            dll->remove(lru);
            delete lru;
        }
       Node* node = new Node(key , value);
       dll->addFront(node);
       mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
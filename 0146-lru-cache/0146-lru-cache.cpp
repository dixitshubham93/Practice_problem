#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node *head, *tail;

    DoublyLinkedList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    Node* getLRU() {
        return tail->prev;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    DoublyLinkedList dll;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        Node* node = mp[key];

        dll.remove(node);
        dll.insertFront(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.count(key)) {
            Node* node = mp[key];

            node->val = value;

            dll.remove(node);
            dll.insertFront(node);

            return;
        }

        if (mp.size() == cap) {
            Node* lru = dll.getLRU();

            dll.remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);

        dll.insertFront(node);
        mp[key] = node;
    }
};
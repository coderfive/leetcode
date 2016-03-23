#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    // <key, value>
    struct node {
        int value, key;
        node *prev, *next;
    } nodes;
    // <key, node*>
    unordered_map<int, node*> mp;
    int capacity;
    int size;
public:
    void show() {
        auto i = nodes.next;
        while (i != &nodes) {
            std::cout << "<" << i->key << ", " << i->value << "> ";
            i = i->next;
        }
        std::cout << std::endl;
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        nodes.next = nodes.prev = &nodes;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            renew_node (it->second);
            return nodes.next->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            if (capacity <= 0) return;
            if (size == capacity) {
                auto last = nodes.prev;
                nodes.prev = last->prev;
                nodes.prev->next = &nodes;
                mp.erase(mp.find(last->key));
                delete last;
                size--;
            }
            auto n = new node ();
            n->key = key;
            n->value = value;
            mp[key] = n;
            n->prev = &nodes;
            n->next = nodes.next;
            nodes.next = n;
            n->next->prev = n;
            size++;
        }
        else {
            it->second->value = value;
            renew_node (it->second);
        }
    }
    void renew_node (node* old_node) {
        if (old_node != nodes.next) {
            auto i = old_node;
            auto b = nodes.next;
            i->prev->next = i->next;
            i->next->prev = i->prev;
            i->next = b;
            b->prev = i;
            nodes.next = i;
            i->prev = &nodes;
        }
    }
};

int main() {
    LRUCache lru (1);
    lru.set(2,1);
    lru.get(2);
    lru.set(3,2);
    lru.get(2);
    lru.get(3);

    LRUCache lru2 (2);
    lru2.set(2,1);
    lru2.show();
    lru2.set(2,2);
    lru2.show();
    lru2.get(2);
    lru2.show();
    lru2.set(1,1);
    lru2.show();
    lru2.set(4,1);
    lru2.show();
    lru2.get(2);
    lru2.show();
    return 0;
}

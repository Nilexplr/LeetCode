#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

struct node_t
{
    int key;
    int value;
    node_t *prev;
    node_t *next;
    int used;
};


class LRUCache {
    protected:
        int _capacity;
        int _size;
        std::unordered_map<int, node_t> _cache;
        node_t *_last_used;

    public:
        LRUCache(int capacity) {
            _capacity = capacity;
            _cache = {};
            _last_used = NULL;
            _size = 0;
        }
        ~LRUCache() {
            
        }
        virtual void add_node(node_t *node) {
            node->next = _last_used->next;
            _last_used->next->prev = node;
            _last_used->next = node;
            node->prev = _last_used;
            _last_used = node;
        }
        void drop_node(node_t *node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        virtual int used_node(node_t *recently_used) {
            if (recently_used == _last_used)
                return recently_used->value;
            drop_node(recently_used);
            add_node(recently_used);
            return recently_used->value;

        }
        void erase_node(node_t *to_add) {
            int key_to_erase = _last_used->next->key;
                
            drop_node(&_cache[key_to_erase]);
            _cache.erase(key_to_erase);
            add_node(to_add);
        }
        int get(int key) {
            if (_cache.find(key) == _cache.end())
                return -1;
            node_t *recently_used = &_cache[key];
            return used_node(recently_used);
        }
        
        void put(int key, int value) {
            node_t node = {node.key = key, node.value = value, node.next = NULL, node.prev = NULL, node.used = 0};
            
            if (_cache.find(key) != _cache.end()) {
                _cache[key].value = value;
                node_t *recently_used = &_cache[key];
                used_node(recently_used);
                return;
            }
            
            _cache[key] = node;
            node_t *node_ptr =  &_cache[key];


            if (_last_used == NULL) {
                _last_used = node_ptr;
                _cache[key].next = node_ptr;
                _cache[key].prev = node_ptr;
                _size++;
                return;
            }
            if (_capacity == 1) {
                _cache.erase(_last_used->key);
                _last_used = node_ptr;
                return;
            }
            if (_capacity - _size > 0) {
                _size++;
                add_node(node_ptr);
            } else {
                erase_node(node_ptr);
            }
        }
};

class LFUCache : public LRUCache {
    public:
        LFUCache(int capacity) : LRUCache(capacity) {
        }
        ~LFUCache() {
            
        }
        void add_right(node_t *root, node_t *to_add) {
            to_add->next = root->next;
            root->next->prev = to_add;
            root->next = to_add;
            to_add->prev = root;
        }
        void add_left(node_t *root, node_t *to_add) {
            to_add->next = root;
            root->prev->next = to_add;
            to_add->prev = root->prev;
            root->prev = to_add;
        }
        void add_node(node_t *node) override {
            node_t *it = _last_used->next;
            if (node->next != NULL)
                it = node->next;
            while (it != _last_used && node->used >= it->used)
            {
                it = it->next;
            }
            if (it == _last_used && it->used <= node->used) {
                add_right(it, node);
                _last_used = node;
            } else
                node->used < it->used ? add_left(it, node) : add_right(it, node);
        }
        
        int used_node(node_t *recently_used) override {
            recently_used->used++;
            if (recently_used == _last_used)
                return recently_used->value;
            
            drop_node(recently_used);
            add_node(recently_used);
            return recently_used->value;
        }

};

int main() 
{
//    LFUCache lRUCache = LFUCache(10);
//    std::vector<std::string> instr = { std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("get"),std::string("get"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("get"),std::string("get"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("get"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("get"),std::string("put"),std::string("get"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("get"),std::string("get"),std::string("get"),std::string("put"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("get"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("get"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("put"),std::string("put")};
//    std::vector<std::pair<int, int>> num = {{10,13},{3,17},{6,11},{10,5},{9,10},{13,0},{2,19},{2,0},{3,0},{5,25},{8,0},{9,22},{5,5},{1,30},{11,0},{9,12},{7,0},{5,0},{8,0},{9,0},{4,30},{9,3},{9,0},{10,0},{10,0},{6,14},{3,1},{3,0},{10,11},{8,0},{2,14},{1,0},{5,0}, {4,0},{11,4},{12,24},{5,18},{13,0},{7,23},{8,0},{12,0},{3,27},{2,12},{5,0},{2,9},{13,4},{8,18},{1,7},{6,0},{9,29},{8,21},{5,0},{6,30},{1,12},{10,0},{4,15},{7,22},{11,26},{8,17},{9,29},{5,0},{3,4},{11,30},{12,0},{4,29},{3,0},{9,0},{6,0},{3,4},{1,0},{10,0},{3,29},{10,28},{1,20},{11,13},{3,0},{3,12},{3,8},{10,9},{3,26},{8,0},{7,0},{5,0},{13,17},{2,27},{11,15},{12,0},{9,19},{2,15},{3,16},{1,0},{12,17},{9,1},{6,19},{4,0},{5,0},{5,0},{8,1},{11,7},{5,2},{9,28},{1,0},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};

//    LFUCache lRUCache = LFUCache(2);
//    std::vector<std::string> instr = {"put","put","get","put","get","get","put","get","get","get"};
//    std::vector<std::pair<int, int>> num = {{1,1},{2,2},{1,0},{3,3},{2,0},{3,0},{4,4},{1,0},{3,0},{4,0}};

    LFUCache lRUCache = LFUCache(3);
    std::vector<std::string> instr = {"put","put","get","get","get","put","put","get","get","get","get"};
    std::vector<std::pair<int, int>> num = {{2,2},{1,1},{2,0},{1,0},{2,0},{3,3},{4,4},{3,0},{2,0},{1,0},{4,0}};

    int i = 0;
    for (auto &action : instr) {
        if (action == "put")
            lRUCache.put(num[i].first, num[i].second);
        if (action == "get")
            std::cout << lRUCache.get(num[i].first) << std::endl;
        i++;
    }
}
#include <list>
#include <map>
#include "util.h"

using namespace std;

typedef struct {
    int key, value;
} item_t;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (lut.count(key) > 0) {
            item_t item = *(lut[key]);
            cache.erase(lut[key]);
            cache.push_front(item);
            lut[key] = cache.begin();
            return item.value;
        } else return -1;
    }
    
    void put(int key, int value) {
        if (lut.count(key) > 0) {
            cache.erase(lut[key]);
        } else if (cache.size() >= capacity) {
            item_t least = cache.back();
            cache.erase(lut[least.key]);
            lut.erase(least.key);
        }
        item_t item = {.key = key, .value = value};
        cache.push_front(item);
        lut[key] = cache.begin();
    }
private:
    int capacity;
    list<item_t> cache;
    map<int, list<item_t>::iterator> lut;
};

int main() {
    LRUCache* lru = new LRUCache(2);
    lru -> put(1, 1);
    lru -> put(2, 2);
    cout << lru -> get(1) << endl;
    lru -> put(3, 3);
    cout << lru -> get(2) << endl;
    lru -> put(4, 4);
    cout << lru -> get(1) << endl;
    cout << lru -> get(3) << endl;
    cout << lru -> get(4) << endl;
    return 0;
}
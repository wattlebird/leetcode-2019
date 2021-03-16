#include "util.h"
#include <map>
#include <list>

using namespace std;

typedef struct {
    int key;
    int value;
    int freq;
    int timestamp;
} Item;

class LFUCache {
public:
    LFUCache(int capacity) {
        heap = vector<Item>(capacity);
    }
    
    int get(int key) {
        time++;
        if (G[key] == -1) {
            return -1;
        }
        int rtn = heap[G[key]].value;
        heap[G[key]].freq++;
        heap[G[key]].timestamp = time;
        sink(G[key]);
        return rtn;
    }
    
    void put(int key, int value) {
        time++;
        if (G[key] != -1) { // the item already exists in heap
            heap[G[key]].freq++;
            heap[G[key]].timestamp = time;
            heap[G[key]].value = value;
            sink(G[key]);
        } else { // the item does not exist
            if (heap.empty()) return;
            if (heap_size == heap.size()) { // item does not exist, one needs to pop first!
                heapswap(0, --heap_size);
                G[heap[heap_size].key] = -1;
                sink(0);
            }
            heap[heap_size] = {.key = key, .value = value, .freq = 1, .timestamp = time};
            G[key] = heap_size++;
            swim(G[key]);
        }
    }
private:
    vector<int> G = vector<int>(10001, -1);
    vector<Item> heap;
    int heap_size = 0;
    int time = 0;

    void heapswap(int i, int j) {
        swap(heap[i], heap[j]);
        G[heap[i].key] = i;
        G[heap[j].key] = j;
    }

    void sink(int i) {
        if (i > heap_size / 2) return;
        int cur = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if (l < heap_size) cur = compare(i, l) ? cur : l;
        if (r < heap_size) cur = compare(cur, r) ? cur : r;
        if (cur != i) {
            heapswap(cur, i);
            sink(cur);
        }
    }

    void swim(int i) {
        if (i == 0) return;
        int f = (i - 1) / 2;
        if (!compare(f, i)) {
            heapswap(f, i);
            swim(f);
        }
    }

    bool compare(int i, int j) { // ideally, return true if heap[i] < heap[j]
        if (heap[i].freq != heap[j].freq) return heap[i].freq < heap[j].freq;
        else return heap[i].timestamp < heap[j].timestamp;
    }
};

int main() {
    LFUCache* obj = new LFUCache(2);
    obj -> put(1,1);
    obj -> put(2,2);
    cout << obj -> get(1) <<endl;
    obj -> put(3,3);
    cout << obj -> get(2) <<endl;
    cout << obj -> get(3) <<endl;
    obj -> put(4,4);
    cout << obj -> get(1) <<endl;
    cout << obj -> get(3) <<endl;
    cout << obj -> get(4) <<endl;
    return 0;
}
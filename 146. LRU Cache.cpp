struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) :
        key(k), value(v) { }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        auto temp_iter = cache.begin();
        while (temp_iter != cache.end()) {
            if (temp_iter->key == key) break;
            ++temp_iter;
        }
        if (temp_iter == cache.end()) return -1;
        int temp_key = temp_iter->key;
        int temp_value = temp_iter->value;
        cache.erase(temp_iter);
        cache.push_back(CacheNode(temp_key, temp_value));
        return temp_value;
    }
    
    void put(int key, int value) {
        if (cache.empty()) {
            cache.push_back(CacheNode(key, value));
            return;
        }
        auto temp_iter = cache.begin();
        while (temp_iter != cache.end()) {
            if (temp_iter->key == key) break;
            ++temp_iter;
        }
        if (temp_iter != cache.end()) {
            cache.erase(temp_iter);
            cache.push_back(CacheNode(key, value));
        } else {
            cache.push_back(CacheNode(key, value));
            if (cache.size() > max_cap) cache.pop_front();
        }
    }
    
private:
    list<CacheNode> cache;
    int max_cap;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

// 执行用时：296 ms
// 已经战胜 10.98 % 的 cpp 提交记录
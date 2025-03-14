/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        if (capacity >= 0){
            this->capacity_ = capacity;
        } else {
            this->capacity_ = 0;
        }
        this->used_ = 0;
    }

    ~LRUCache(){}
    
    int get(int key) {
        if ((capacity_ == 0) || (used_ == 0)) return -1;
        auto it = cache_.find(key);
        if (it != cache_.end()){
            it->second->second++;
            return it->second->first;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) return;
        if (capacity_ <= used_){
            // evict
            int evict_key = 0;
            while (evict_key < key){
                auto it = cache_.find(evict_key);
                if (it != cache_.end()){
                    break;
                } 
                evict_key++;
            }
            cache_.erase(evict_key);
            cache_.insert(pair<int, int>(key, value));
        } else {
            // append
            cache_.insert(pair<int, pair<int, int>>(key, make_pair(value, 0)));
            used_++;
        }
    }

private:
    int capacity_{0};
    int used_{0};
    map<int, pair<int, int>> cache_; // <key, <value, freq> >
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


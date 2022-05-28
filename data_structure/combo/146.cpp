/*
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
        auto it = m_.find(key);
        if (it != m_.end()) {
            // found it, move it the begin of l_
            l_.splice(l_.begin(), l_, it->second);
            return it->second->second;;
        }
        // not found
        return -1;
    }
    
    void put(int key, int value) {
        auto it = m_.find(key);
        //found it
        if (it != m_.cend()) {
            //update the node in list
            it->second->second = value;
            l_.splice(l_.begin(), l_, it->second);
            return;
        }
        // not found it
        // oversize
        if (m_.size() == capacity_) {
            //remove the last it in list
            const auto& to_remove = l_.back();
            //rm list and map
            m_.erase(to_remove.first);
            l_.pop_back();
        }
        l_.emplace_front(key, value);
        m_[key] = l_.begin();
    }
private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    list<pair<int, int>> l_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

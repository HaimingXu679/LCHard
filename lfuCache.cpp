// https://leetcode.com/problems/lfu-cache/

// Hashmap, linked list

// O(1), faster than 5%

class LFUCache {
public:
    unordered_map<int, int> values, freq;
    map<int, list<int> > linked;
    int c;
    
    LFUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if (values.count(key) == 0 || c == 0)
            return -1;
        list<int>::iterator it;
        for (it = linked[freq[key]].begin(); it != linked[freq[key]].end(); it++) {
            if (*it == key) {
                linked[freq[key]].erase(it);
                break;
            }
        }
        linked[++freq[key]].push_back(key);
        return values[key];
    }
    
    void put(int key, int value) {
        if (values.find(key) != values.end()) {
            values[key] = value;
            get(key);
        } else {
            if (values.size() >= c) {
                map<int, list<int> >::iterator it;
                for (it = linked.begin(); it != linked.end(); it++) {
                    if ((it -> second).size() > 0) {
                        values.erase(*(it -> second).begin());
                        freq.erase(*(it -> second).begin());
                        (it -> second).pop_front();
                        break;
                    }
                }
            }
            values[key] = value;
            freq[key] = 1;
            linked[1].push_back(key);
        }
    }
};

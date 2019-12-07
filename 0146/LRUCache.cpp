class LRUCache {
public:
    int cap;
    unordered_map<int, array<int, 2>> map; // 0:val, 1:ref
    queue<array<int, 2>, deque<array<int, 2>>> q; // 0:key, 1:ref
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        //cout << "get:" << key << endl;
        if (map.find(key) == map.end())
            return -1;
        else {
            auto ele = map.find(key);
            ele->second[1]++;
            q.push({key, ele->second[1]});
            //cout << "return:" << map.find(key)->second[0] << endl;
            return ele->second[0];
        }
    }
    
    void put(int key, int value) {
        //cout << "put:" << key << " " << value << endl;
        if (map.find(key) == map.end()) {
            // insert
            //cout << "insert new:" << key << " " << value << endl;
            q.push({key, 0});
            if (map.size() == cap) {
                while (1) {
                    int key = q.front()[0];
                    int ref = q.front()[1];
                    q.pop();
                    if (ref == map[key][1]) {
                        //cout << "erase:" << key << " " << ref << endl;
                        map.erase(key);
                        break;
                    }
                    //cout << "erase:" << key << endl;
                }
            }
            map[key][0] = value;
            map[key][1] = 0;
        } else {
            // update
            map[key][0] = value;
            map[key][1]++;
            q.push({key, map[key][1]});
            //cout << "update:" << key << " " << map[key][0] << " " << map[key][1] << endl;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

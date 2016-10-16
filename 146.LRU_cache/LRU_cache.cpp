class LRUCache{
public:
    int _cap;
    list<int> _list;
    unordered_map<int, int> _val;
    unordered_map<int, list<int>::iterator> _pos;

    LRUCache(int capacity) {
        _cap = capacity;
        _list.clear();
        _val.clear();
        _pos.clear();
    }
    
    void update(int key, int value) {
        _val[key] = value;
        _list.erase(_pos[key]);
        _list.push_front(key);
        _pos[key] = _list.begin();
    }
    
    int get(int key) {
        if (_val.find(key) == _val.end()) {
            return -1;
        } else {
            int val = _val[key];
            update(key, val);
            return val;
        }
    }
    
    void set(int key, int value) {
        if (_val.find(key) == _val.end()) {
            if (_list.size() == _cap) {
                int k = _list.back();
                _val.erase(k);
                _pos.erase(k);
                _list.pop_back();
            }
            _list.push_front(key);
            _pos[key] = _list.begin();
            _val[key] = value;
        } else {
            update(key, value);
        }
    }
};

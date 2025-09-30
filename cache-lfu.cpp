class Node {
public:
    int key, value, count;
    Node *next, *prev;

    Node(int key, int value, int count) {
        this->key = key;
        this->value = value;
        this->count = count;
    }

    ~Node() {
        delete next;
        delete prev;
        next = prev = nullptr;
    }
};

class List {
private:
    int size;
    Node* head, *tail;

public:
    List() {
        size = 0;
        head = new Node(-1, -1, 0);
        tail = new Node(-1, -1, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~List() {
        delete head;
    }

    void push_front(Node* node) {
        size++;
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }

    void remove_node(Node* node) {
        if (this->empty()) {
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;
        delete node;
        size--;
    }

    void pop_back() {
        remove_node(this->back());
    }

    Node* front() {
        if (this->empty()) {
            return nullptr;
        }
        return head->next;
    }

    Node* back() {
        if (this->empty()) {
            return nullptr;
        }
        return tail->prev;
    }

    bool empty() { return size == 0; }
};

class LFUCache {
    int capacity, minCount;
    unordered_map<int, Node*> cache;
    unordered_map<int, List*> freqListMap;

    List* getList(int count) {
        if (freqListMap.contains(count)) {
            return freqListMap[count];
        }
        freqListMap[count] = new List();
        return freqListMap[count];
    }

    void updateFreqList(Node* node) {
        cache.erase(node->key);

        int key = node->key, value = node->value, count = node->count;
        Node* newNode = new Node(key, value, count + 1);
        getList(count + 1)->push_front(newNode);
        getList(count)->remove_node(node);

        // update the min frequency tracker.
        if (minCount == count && getList(count)->empty()) {
            minCount++;
        }
        cache[newNode->key] = newNode;
    }

public:
    LFUCache(int capacity) {
        this->minCount = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.contains(key)) {
            updateFreqList(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            updateFreqList(cache[key]);
            cache[key]->value = value;
        } else {
            if (cache.size() == this->capacity) {
                cache.erase(getList(minCount)->back()->key);
                getList(minCount)->pop_back();
            }
            // Insert new cache item
            minCount = 1;
            Node* newNode = new Node(key, value, minCount);
            getList(minCount)->push_front(newNode);
            cache[key] = newNode;
        }
    }
};

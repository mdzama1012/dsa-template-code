class Node {
private:
    int key, value;

public:
    Node *next, *prev;

    Node(int key, int value, Node* next = nullptr, Node* prev = nullptr) {
        this->key = key,
        this->value = value;
        this->next = next;
        this->prev = prev;
    }

    void set_kv(int key, int value) {
        this->key = key;
        this->value = value;
    }

    pair<int, int> get_kv() {
        return {this->key, this->value};
    }
};

class DLL {
private:
    int size;
    Node *head;
    Node *tail;

public:
    DLL() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~DLL() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    bool is_empty() {
        return size == 0;
    }

    // Insert a new node in front of list.
    Node* push_front(int key, int value) {
        Node* newNode = new Node(key, value);

        head->next->prev = newNode;
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;

        size++;
        return newNode;
    }

    // Removes the node from the back of the list.
    Node* pop_back() {
        if (this->is_empty()) {
            return nullptr;
        }

        Node* delNode = tail->prev;
        delNode->prev->next = tail;
        tail->prev = delNode->prev;

        size--;
        return delNode;
    }

    void replace_front(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;

        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
};

class LRUCache {
private:
    DLL list;
    int capacity;
    unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.contains(key)) {
            list.replace_front(cache[key]);
            return cache[key]->get_kv().second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            list.replace_front(cache[key]);
            cache[key]->set_kv(key, value);
            return;
        }

        // Inserting new key, value pair.
        if ((int)cache.size() == capacity) {
            cache.erase(list.pop_back()->get_kv().first);
        }
        cache[key] = list.push_front(key, value);
    }
};

class Node {
public:
    int val;
    Node* ptr = nullptr;
    
    Node(int val) {
        this->val = val;
    }
};

class LinkedList {
public:
    Node* head = nullptr;
    
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->ptr;
            delete current;
            current = next;
        }
    }
    
    void append(int val) {
        Node* node = new Node(val);
        
        if (head == nullptr) {
            head = node;
        } else {
            Node* current = head;
            while (current->ptr != nullptr) {
                current = current->ptr;
            }
            
            current->ptr = node;
        }
    }
    
    void prepend(int val) {
        Node* node = new Node(val);
        Node* oldHead = head;
        head = node;
        node->ptr = oldHead;
    }
    
    int getValueAtIndex(int index) {
        int currentIndex = 0;
        Node* current = head;
        while (currentIndex != index) {
            if (current->ptr != nullptr) {
                current = current->ptr;
                currentIndex++;
            } else {
                std::cout << "Index out of bounds" << std::endl;
                return 0;
            }
        }
        
        return current->val;
    }
    
    std::vector<int> getIndexesWhereValueAppears(int val) {
        std::vector<int> appearances;
        
        int currentIndex = 0;
        Node* current = head;
        while (current) {
            if (current->val == val) {
                appearances.push_back(currentIndex);
            }
            current = current->ptr;
            currentIndex++;
        }
        
        if (appearances.size() == 0) {
            std::cout << "Did not find: " << val << "in list" << std::endl;
        }
        
        return appearances;
    }
    
    void insert(int index, int val) {
        Node* newNode = new Node(val);
        if (index == 0) {
            Node* oldFirst = head;
            head = newNode;
            newNode->ptr = oldFirst;
        } else if (index >= (getTotalNumberNodes() - 1)) {
            int currentIndex = 0;
            Node* current = head;
            while (currentIndex != (index - 1)) {
                if (current->ptr != nullptr) {
                    current = current->ptr;
                    currentIndex++;
                }
            }
            
            Node* nodeAhead = current->ptr;
            current->ptr = newNode;
            newNode->ptr = nodeAhead;
        } else {
            std::cout << "Cannot Insert Out Of Bounds" << std::endl;
        }
    }
    
    void set(int index, int val) {
        Node* current = head;
        int currentIndex = 0;
        
        while (currentIndex < index) {
            if (current->ptr) {
                current = current->ptr;
                currentIndex++;
            }
        }
        
        current->val = val;
    }
    
    void deleteNode(int index) {
        Node* current = head;
        int currentIndex = 0;
        
        if (index > getTotalNumberNodes() - 1) {
            std::cout << "Index Out Of Bounds" << std::endl;
            return;
        }
        
        if (index == 0) {
            Node* oldFirst = head;
            head = oldFirst->ptr;
            delete oldFirst;
        } else {
            while (currentIndex < (index - 1)) {
                if (current->ptr) {
                    current = current->ptr;
                    currentIndex++;
                }
            }
            Node* old = current->ptr;
            current->ptr = old->ptr;
            delete old;
        }
    }
    
    void pop() {
        deleteNode(getTotalNumberNodes() - 1);
    }
    
    void popFront() {
        deleteNode(0);
    }
    
    int getTotalNumberNodes() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->ptr;
        }
        return count;
    }
    
    void reverse() {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current) {
            next = current->ptr;     // Save next node
            current->ptr = prev;     // Reverse pointer
            prev = current;          // Move prev forward
            current = next;          // Move current forward
        }

        head = prev; // Update head to the new front (previously the tail)
    }
    
    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->val << std::endl;
            current = current->ptr;
        }
    }
};

class QueueItem {
public:
    int val;
    QueueItem* next;
    QueueItem* prev;
};

class Queue {
public:
    QueueItem* front = nullptr;
    QueueItem* rear = nullptr;
    
    void enqueue(int x) {
        QueueItem* newitem = new QueueItem();
        newitem->val = x;
        
        // If this is first ever element, make it the front
        if (front == nullptr) {
            std::cout << "First Item" << std::endl;
            front = newitem;
        }
        
        // next value = current rear
        newitem->next = rear;
        
        // if rear is not nullptr then change its previous
        if (rear != nullptr) {
            rear->prev = newitem;
        }
        
        newitem->prev = nullptr;
        rear = newitem;
    }
    
    void dequeue() {
        QueueItem* current = front;
        
        front = current->prev;
        
        delete current;
        
        if (front) {
            front->next = nullptr;
        }
    }
    
    int getFirstItem() {
        if (!isEmpty()) {
            return front->val;
        } else {
            std::cout << "Queue Empty" << std::endl;
            return 0;
        }
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    void printQueue() {
        if (!isEmpty()) {
            std::cout << "Back of Queue" << std::endl;
            QueueItem* current = rear;
            do {
                std::cout << current->val << std::endl;
                current = current->next;
            } while (current != nullptr);
            std::cout << "Front of Queue" << std::endl;
            
        } else {
            std::cout << "Empty Queue" << std::endl;
        }
    }
    
};

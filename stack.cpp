class Stack {
private:
    int arr[100];
    int top;
public:
    Stack() {
        this->top = -1;
    }
    
    bool HasRoom() {
        return top < 99;
    }
    
    bool IsEmpty() {
        return (top < 0);
    }
    
    void Push(int x) {
        if (HasRoom()) {
            top++;
            arr[top] = x;
            std::cout << "Pushed " << x << " To Stack" << std::endl;
        } else {
            std::cout << "Stack Overflow";
        }
    }
    
    int Pop() {
        if (!IsEmpty()) {
            top--;
            return arr[top];
        } else {
            std::cout << "Stack Underflow";
            return 0;
        }
    }
    
    int Peek() {
        if (IsEmpty()) {
            std::cout << "Stack Is Empty" << std::endl;
            return 0;
        }
        return arr[top];
    }
};

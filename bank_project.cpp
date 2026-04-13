

// PART 2: MEMBER 2 (Operations - Queue & Stack)

class BankOperations {
    int queueArray[100];
    int front = 0;
    int rear = 0;

    string stackArray[100];
    int top = -1;

public:
   
    void addToLine(int id) {
        if (rear < 100) {
            queueArray[rear] = id;
            rear++; 
            cout << "\n[Queue] ID " << id << " is at position " << (rear - front) << " in line." << endl;
        } else {
            cout << "\n[Error] Line is full!" << endl;
        }
    }

    void serveCustomer() {
        if (front == rear) {
            cout << "\n[Empty] No one is waiting in the line!" << endl;
        } else {
            cout << "\n[Service] Now serving Customer ID: " << queueArray[front] << endl;
            front++; 
        }
    }

   
    void saveHistory(string action) {
        if (top < 99) {
            stackArray[++top] = action;
        }
    }

    void undoAction() {
        if (top == -1) cout << "\n[History] Nothing to undo!" << endl;
        else cout << "\n[Undo] Reversing last action: " << stackArray[top--] << endl;
    }
};

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// PART 1: MEMBER 1 (Hash Table)
// ==========================================
struct Customer {
    int id;
    string name;
    double balance;
};

Customer accounts[100];
bool isOccupied[100];

int findIndex(int id) {
    int h = id % 100;
    int start = h;
    while (isOccupied[h]) {
        if (accounts[h].id == id) return h;
        h = (h + 1) % 100;
        if (h == start) break;
    }
    return -1;
}

void createAccount(int id, string name, double bal) {
    int h = id % 100;
    while (isOccupied[h]) h = (h + 1) % 100;
    accounts[h].id = id;
    accounts[h].name = name;
    accounts[h].balance = bal;
    isOccupied[h] = true;
    cout << "\n[Success] Account created for " << name << endl;
}

// ==========================================
// PART 2: MEMBER 2 (Queue & Stack Operations)
// ==========================================

// --- Queue: For Token Line ---
int queueLine[100];
int front = 0, rear = 0;

void addToQueue(int id) {
    if (rear < 100) {
        queueLine[rear++] = id; // Enqueue operation
        cout << "\n[Queue] ID " << id << " added to line." << endl;
    }
}

// --- Middle Removal from Queue ---
void leaveLine(int id) {
    int foundIdx = -1;
    for (int i = front; i < rear; i++) {
        if (queueLine[i] == id) {
            foundIdx = i;
            break;
        }
    }
    if (foundIdx != -1) {
        // Shifting elements to maintain Queue order
        for (int i = foundIdx; i < rear - 1; i++) {
            queueLine[i] = queueLine[i + 1];
        }
        rear--;
        cout << "\n[Queue] ID " << id << " left the line." << endl;
    } else {
        cout << "\n[Error] ID not in line!" << endl;
    }
}

void serveNext() {
    if (front == rear) cout << "\n[Empty] No one in line!" << endl;
    else {
        cout << "\n[Service] Now serving ID: " << queueLine[front++] << endl; // Dequeue operation
    }
}

// --- Stack: For History Record ---
string historyStack[100];
int top = -1;

void pushHistory(string msg) {
    if (top < 99) historyStack[++top] = msg;
}

void showLastAction() {
    if (top == -1) cout << "\n[History] No records yet." << endl;
    else cout << "\n[Last Task] " << historyStack[top] << " (Total tasks: " << (top + 1) << ")" << endl;
}

// ==========================================
// PART 3: MEMBER 3 (Menu & Integration)
// ==========================================
int main() {
    for(int i = 0; i < 100; i++) isOccupied[i] = false;
    int choice, id;
    string name;
    double bal;

    while (true) {
        cout << "\n--- BUBT BANKING SYSTEM (Queue & Hash) ---" << endl;
        cout << "1. Create Account (Hash Table)" << endl;
        cout << "2. Join Line (Queue Enqueue)" << endl;
        cout << "3. Leave Line (Queue Removal)" << endl;
        cout << "4. Service Next (Queue Dequeue)" << endl;
        cout << "5. Search Account (Hash Table Search)" << endl;
        cout << "6. View Last Action (Stack Top)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            string discard; getline(cin, discard);
            continue;
        }

        if (choice == 7) break;

        switch (choice) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Deposit: "; cin >> bal;
                createAccount(id, name, bal);
                pushHistory("Created Account ID: " + to_string(id));
                break;
            case 2:
                cout << "Enter ID: "; cin >> id;
                addToQueue(id);
                pushHistory("ID " + to_string(id) + " joined line.");
                break;
            case 3:
                cout << "Enter ID to leave: "; cin >> id;
                leaveLine(id);
                pushHistory("ID " + to_string(id) + " left line.");
                break;
            case 4:
                serveNext();
                pushHistory("Customer served.");
                break;
            case 5:
                cout << "Search ID: "; cin >> id;
                int idx; idx = findIndex(id);
                if (idx != -1) cout << "Found: " << accounts[idx].name << " | Bal: $" << fixed << setprecision(2) << accounts[idx].balance << endl;
                else cout << "Not Found!" << endl;
                break;
            case 6:
                showLastAction();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

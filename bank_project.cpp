#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

// PART 1: MEMBER 1 (Data Structure & Database)

struct Customer {
    int id;
    string name;
    double balance;
};
class BankDatabase {
    Customer table[100];
    bool isFull[100];

public:
    BankDatabase() {
        for(int i = 0; i < 100; i++) isFull[i] = false;
    }

    // Hash Function: 
    int getHash(int id) { return id % 100; }

    void addAccount(int id, string name, double bal) {
        int index = getHash(id);
        table[index].id = id;
        table[index].name = name;
        table[index].balance = bal;
        isFull[index] = true;
        cout << "\n[Success] Account created for " << name << " (ID: " << id << ")" << endl;
    }

    void findAndShow(int id) {
        int index = getHash(id);
        if (isFull[index] && table[index].id == id) {
            cout << "\n--- Account Details ---" << endl;
            cout << "Name: " << table[index].name << endl;
            cout << "Balance: $" << fixed << setprecision(2) << table[index].balance << endl;
        } else {
            cout << "\n[Error] Account not found!" << endl;
        }
    }
};
// ==========================================
// PART 2: MEMBER 2 (Operations - Token Queue)
// কাজ: ব্যাংকের সিরিয়াল বা টোকেন লাইন মেইনটেইন করা
// ==========================================

class BankOperations {
    int queueArray[100]; // ১০০ জনের ওয়েটিং লাইন
    int front = 0;       // লাইনের শুরু
    int rear = 0;        // লাইনের শেষ

public:
    // Queue Logic: First-In First-Out (FIFO)
    void addToLine(int id) {
        if (rear < 100) {
            queueArray[rear] = id;
            rear++; // লাইনের পেছনে একজন যুক্ত হলো
            cout << "\n[Queue] ID " << id << " added to the line. Position: " << (rear - front) << endl;
        } else {
            cout << "\n[Error] Waiting line is full!" << endl;
        }
    }

    void serveCustomer() {
        if (front == rear) {
            cout << "\n[Empty] No one is waiting in the line!" << endl;
        } else {
            cout << "\n[Service] Now serving Customer ID: " << queueArray[front] << endl;
            front++; // সেবা দেওয়া শেষ, পরের জন সামনে আসবে
        }
    }
};



    void undoAction() {
        int main() {
    BankDatabase myBank;
    BankOperations myOps;
    int choice, id;
    string name;
    double bal;

    while (true) {
        cout << "\n====================================" << endl;
        cout << "      BANK MANAGEMENT SYSTEM        " << endl;
        cout << "====================================" << endl;
        cout << " 1. Open New Account" << endl;
        cout << " 2. Search Account Info" << endl;
        cout << " 3. Join Waiting Line (Queue)" << endl;
        cout << " 4. Serve Next Customer (Dequeue)" << endl;
        cout << " 5. Undo Last Action (Stack)" << endl;
        cout << " 6. Exit" << endl;
        cout << "------------------------------------" << endl;
        cout << " ENTER CHOICE: ";
        cin >> choice;

        if (choice == 6) {
            cout << "\nExiting... Thank you!" << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Deposit Amount: "; cin >> bal;
                myBank.addAccount(id, name, bal);
                myOps.saveHistory("Created Account: " + name);
                break;
            case 2:
                cout << "Enter ID to search: "; cin >> id;
                myBank.findAndShow(id);
                break;
            case 3:
                cout << "Enter ID for Token: "; cin >> id;
                myOps.addToLine(id);
                break;
            case 4:
                myOps.serveCustomer();
                break;
            case 5:
                myOps.undoAction();
                break;
            default:
                cout << "\n[Invalid] Please select 1-6." << endl;
        }
    }
    return 0;
}
        if (top == -1) cout << "\n[History] Nothing to undo!" << endl;
        else cout << "\n[Undo] Reversing last action: " << stackArray[top--] << endl;
    }
};

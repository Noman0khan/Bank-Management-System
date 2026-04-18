#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// PART 1: MEMBER 1 (Data & Hashing)

struct Customer {
    int id;
    string name;
    double balance;
};

Customer accounts[100]; 
bool isOccupied[100];   

void createAccount(int id, string name, double bal) {
    int index = id % 100; // Feature: Hash Table for efficient searching
    accounts[index].id = id;
    accounts[index].name = name;
    accounts[index].balance = bal;
    isOccupied[index] = true;
    cout << "\n[Success] Account created for " << name << endl;
}

void searchAccount(int id) {
    int index = id % 100;
    if (isOccupied[index] && accounts[index].id == id) {
        cout << "\n--- Account Details ---" << endl;
        cout << "Name: " << accounts[index].name << endl;
        cout << "Balance: $" << fixed << setprecision(2) << accounts[index].balance << endl;
    } else {
        cout << "\n[Error] Account not found!" << endl;
    }
}

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
// PART 3: MEMBER 3 (Main Menu & Integration)
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
        cout << " 1. Open New Account (Hashing)" << endl;
        cout << " 2. Search Account Info" << endl;
        cout << " 3. Join Waiting Line (Queue)" << endl;
        cout << " 4. Serve Next Customer (Dequeue)" << endl;
        cout << " 5. Exit" << endl;
        cout << "------------------------------------" << endl;
        cout << " ENTER CHOICE: ";
        cin >> choice;

        if (choice == 5) {
            cout << "\nExiting... Thank you!" << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Deposit Amount: "; cin >> bal;
                myBank.addAccount(id, name, bal);
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
            default:
                cout << "\n[Invalid] Please select a valid option (1-5)." << endl;
        }
    }
    return 0;
}

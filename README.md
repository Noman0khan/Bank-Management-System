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

#include <iostream>
#include <string>

using namespace std;

#define MAX 100

class BankQueue {
private:
    string customers[MAX];
    int front;
    int rear;
    int totalServed;
    int serviceTimePerCustomer;

public:
    BankQueue(int timePerCustomer = 5) {
        front = 0;
        rear = -1;
        totalServed = 0;
        serviceTimePerCustomer = timePerCustomer;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void newCustomer(const string &name) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more customers.\n";
            return;
        }

        rear++;
        customers[rear] = name;

        cout << "Customer \"" << name << "\" added to the queue.\n";

        int waitingCustomers = rear - front;
        cout << "Expected waiting time: "
             << waitingCustomers * serviceTimePerCustomer
             << " minutes.\n";
    }

    void serveCustomer() {
        if (isEmpty()) {
            cout << "No customers in the queue.\n";
            return;
        }

        string servedCustomer = customers[front];
        front++;
        totalServed++;

        cout << "Customer \"" << servedCustomer << "\" has been served.\n";
        cout << "Total customers served: " << totalServed << endl;

        // Reset queue if empty to reuse space
        if (isEmpty()) {
            front = 0;
            rear = -1;
        }
    }

    void showQueue() {
        if (isEmpty()) {
            cout << "The queue is empty.\n";
            return;
        }

        cout << "\nCurrent queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << customers[i] << endl;
        }
    }
};

int main() {
    BankQueue bank;
    int choice;
    string name;

    do {
        cout << "\n--- Bank Queue Management System ---\n";
        cout << "1. Add New Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // clear newline

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, name);
                bank.newCustomer(name);
                break;

            case 2:
                bank.serveCustomer();
                break;

            case 3:
                bank.showQueue();
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;
#define MAX 5

struct MoneyBundle {
	string serialNumber;
	string currencyType;
	int billCounts[3];

};

struct CustomerQueue {
	string customerName;
	string transactionType;
};

struct Node {
    MoneyBundle data;
    Node* next;
};

Node* top = nullptr;

CustomerQueue queue[MAX];
int front = -1;
int rear = -1;


void receiveMoney(){
	//Add a new money bundle to the top of the safe (stack).
    Node* newNode = new Node();

	cout << "Enter serial number: ";
	cin >> newNode->data.serialNumber;
	cout << "Enter currency type: ";
	cin >> newNode->data.currencyType;
	cout << "Enter count of $10 bills: ";
	cin >> newNode->data.billCounts[0];
	cout << "Enter count of $20 bills: ";
	cin >> newNode->data.billCounts[1];
	cout << "Enter count of $50 bills: ";
	cin >> newNode->data.billCounts[2];

	newNode->next = top;
	top = newNode;

}

void newCustomer(){
	//Add a new customer to the end of the bank queue.
	if ((rear + 1) % MAX == front) {
		cout << "Bank queue is full!" << endl;
		return;
	}
	if (front == -1) front = 0;

	rear = (rear + 1) % MAX;

	cout << "Enter customer name: ";
	cin >> queue[rear].customerName;
	cout << "Enter transaction type: ";
	cin >> queue[rear].transactionType;
}

void dequeue(){
	if (front == -1) {
		cout << "There is no customer waiting\n" << endl;
		return;
	}
	if (top == nullptr) {
		cout << "Stack is empty\n" << endl;
		return;
	}
	CustomerQueue served = queue[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front = (front + 1) % MAX;
	}

	Node* temp = top;
	string sNo = top->data.serialNumber;
	top = top->next;
	delete temp;

	cout << " Success!" << endl;
	cout << " Customer " << served.customerName << ", took " << sNo << " serial No. money." << endl;

}

void display() {

	cout << "\n----Stack----\n";
	Node* temp = top;
	while (temp != nullptr) {
		cout << temp->data.serialNumber << "\n";
		temp = temp->next;
	}
	if (top == nullptr) cout << "EMPTY\n";

	cout << "\n----Customer:----\n";

	if (front == -1) {
		cout << "EMPTY\n";
	}else {
		int i = front;
		while (true) {
			cout << queue[i].customerName << "\n\n";
			if (i == rear) break;
			i = (i + 1) % MAX;
		}
	}
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Receive Money\n2. New Customer\n3. Process Transaction\n4. Display\n5. Exit\nChoice:";
        cin >> choice;

        switch (choice) {
        case 1: receiveMoney(); break;
        case 2: newCustomer(); break;
        case 3: dequeue(); break;
        case 4: display(); break;
        case 5: return 0;
        default: cout << "Invalid choice." << endl;
        }
    }
	return 0;
}
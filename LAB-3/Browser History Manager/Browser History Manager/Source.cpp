#include <iostream>
#include <string>

using namespace std;

struct Page {
	string url;
	string title;
	int accessTime[3];
	Page* next;
    Page* prev;
};
Page* head = nullptr;
Page* current = nullptr;

void visit(string u, string t, int h, int m, int s) {
    Page* newPage = new Page;
    newPage->url = u;
    newPage->title = t;
    newPage->accessTime[0] = h;
    newPage->accessTime[1] = m;
    newPage->accessTime[2] = s;
    newPage->next = nullptr;
    newPage->prev = nullptr;

    if (head == nullptr) {
        head = newPage;
        current = head;
    }
    else {

        Page* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newPage;
        newPage->prev = temp;
        current = newPage;
    }
}

void goBack() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        cout << current->title << endl;
    }
    else {
        cout << "Invalid attempt" << endl;
    }
}

void goForward() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        cout << current->title << endl;
    }
    else {
        cout << "Invalid Attempt" << endl;
    }
}
void deleteEntry() {
    if (current == nullptr) return;

    Page* toDelete = current;

    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    }
    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
    }

    if (toDelete == head) {
        head = toDelete->next;
    }

    if (toDelete->prev != nullptr) {
        current = toDelete->prev;
    }
    else {
        current = toDelete->next;
    }

    delete toDelete;
}

void displayHistory() {
    Page* temp = head;
    cout << "--History--" << endl;
    while (temp != nullptr) {

        if (temp == current) cout << "Now: ";

        cout << temp->title << " (" << temp->url << ") Time: ";

        for (int i = 0; i < 3; i++) {
            cout << temp->accessTime[i];
        }
        cout << endl;
        temp = temp->next;
    }
}
void clearMemory() {
    Page* temp = head;
    while (temp != nullptr) {
        Page* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
    current = nullptr;

}

int main() {
    int choice;
    while (true) {
        cout << "\n1-Visit\n2-Back\n3-Forward\n4-Delete\n5-List\n0-EXIT: ";
        cin >> choice;

        if (choice == 0) {
            clearMemory();
            break;
        }

        switch (choice) {
        case 1: {
            string u, t;
            int h, m, s;

            cout << "URL (ex: google.com): ";
            cin >> u;
            cout << "Title: ";
            cin >> t;
            cout << "Time (Hour, minute, second): ";
            cin >> h >> m >> s;

            visit(u, t, h, m, s);
            break;
        }
        case 2: goBack(); break;
        case 3: goForward(); break;
        case 4: deleteEntry(); break;
        case 5: displayHistory(); break;
        default: cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
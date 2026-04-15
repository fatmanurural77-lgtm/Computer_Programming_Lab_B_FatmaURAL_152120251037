#include <iostream>
#include <string>
using namespace std;

// --- STEP 1: STRUCT (Node Structure) ---
struct Player {
    int id;
    int level;
    string nickname;
    Player* next; // Pointer to the next player in the list
};

// --- STEP 2: STACK (Last Actions / Undo) ---
// LIFO: Last-In-First-Out
int actions[5];
int top = -1;

void pushAction(int actionId) {

    if (top == 4) {
        cout << "Oh no! Stack is full";
        return;
    }

    top++;

    actions[top] == actionId;
}

// --- STEP 3: QUEUE (Matchmaking Queue) ---
// FIFO: First-In-First-Out
int matchQueue[5];
int front = 0, rear = 0;

void enqueue(int playerId) {
    // Assign playerId to matchQueue[rear] and increment rear
    // ...
    if (rear == 5) {
        cout << "Queue is full!" << endl;
        return;
    }
    matchQueue[rear] == playerId;
     
    rear++;
}

int main() {
    // --- STEP 4: LINKED LIST (Adding Player to Lobby) ---
    // Create a pointer named 'p1' and allocate memory with NEW
    // ...

    // Set properties: id=1, level=50, nickname="Fatma", next=NULL
    // ...
    // ...
    // ...
    // ...

    // --- STEP 5: USING THE STACK ---
    // Push an action with ID 100 (e.g., "Shoot") into the stack
    // ...

    // --- STEP 6: USING THE QUEUE ---
    // Add player with ID 1 to the matchmaking queue
    // ...

    cout << "System initialized successfully!" << endl;

    // --- STEP 7: MEMORY CLEANUP ---
    // Delete the allocated memory for p1 to avoid memory leaks
    // ...

    return 0;
}
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node {
	string songName;
	Node* next;
};

void display(Node* head) {
	if (head == NULL) {
		cout << "The playlist is empty" << endl;
		return;
	}

	Node* temp = head;
	int count = 1;
	while (temp != NULL) {
		cout << count << ". song: " << temp->songName << endl;
		temp = temp->next;
		count++;
	}
}

void addSong(Node*& head) {

	Node* newSong = new Node;
	cout << "Enter song title: ";
	cin >> newSong->songName;

	newSong->next = head;
	head = newSong;

	cout << "Song added to the playlist." << endl;
}

void searchSong(Node*& head) {

	string song;
	cout << "Enter song title to search: ";
	cin >> song;

	Node* temp = head;

	while (temp != NULL) {
		if (temp->songName == song) {
			cout << "Song has found" << endl;
			return;
		}
		temp = temp->next;
	}
	
	cout << "Song not found." << endl;
}

int main(){
	int choice;
	Node* head = NULL;

	do {
		cout << "---- Playlist ----" << endl;
		cout << "1. Add a song" << endl;
		cout << "2. Search for a song" << endl;
		cout << "3. Display the Playlist" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1: addSong(head); break;
		case 2: searchSong(head); break;
		case 3: display(head); break;
		case 4: return 0;
		default: cout << "Invalid choice." << endl;
		}
	} while (choice != 4);
}
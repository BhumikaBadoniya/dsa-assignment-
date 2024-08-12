#include <iostream>
#include <cstring>

using namespace std;

// Define the node structure
struct Node {
    char name[100];
    Node* next;
};

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = new Node();
    strcpy(newNode->name, name);
    newNode->next = nullptr;
    return newNode;
}

// Function to get the length of the linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to add a node at the beginning
void addAtBeg(Node** head, const char* name) {
    Node* newNode = createNode(name);
    newNode->next = *head;
    *head = newNode;
}

// Function to append a node at the end
void append(Node** head, const char* name) {
    Node* newNode = createNode(name);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add a node at a specific position
void addAtPOS(Node** head, const char* name, int pos) {
    if (pos == 0) {
        addAtBeg(head, name);
        return;
    }
    Node* newNode = createNode(name);
    Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to display more details of the linked list
void displayMORE(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Address: " << temp << ", Value: " << temp->name << ", Next: " << temp->next << endl;
        temp = temp->next;
    }
}

// Function to remove the first node
void removeFirst(Node** head) {
    if (*head == nullptr) {
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

// Function to remove the last node
void removeLast(Node** head) {
    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to remove a node at a specific position
void removePOS(Node** head, int pos) {
    if (*head == nullptr) {
        return;
    }
    if (pos == 0) {
        removeFirst(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

int main() {
    Node* head = nullptr;

    // Example usage
    append(&head, "Alice");
    append(&head, "Bob");
    addAtBeg(&head, "Charlie");
    addAtPOS(&head, "David", 2);
    display(head);
    displayMORE(head);
    cout << "Length: " << getLength(head) << endl;
    removeFirst(&head);
    display(head);
    removeLast(&head);
    display(head);
    removePOS(&head, 1);
    display(head);

    return 0;
}

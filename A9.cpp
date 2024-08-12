#include <iostream>

using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
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
void addAtBeg(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to append a node at the end
void append(Node** head, int data) {
    Node* newNode = createNode(data);
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
void addAtPOS(Node** head, int data, int pos) {
    if (pos == 0) {
        addAtBeg(head, data);
        return;
    }
    Node* newNode = createNode(data);
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to display more details of the linked list
void displayMORE(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Address: " << temp << ", Value: " << temp->data << ", Next: " << temp->next << endl;
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

// Function to segregate odd and even nodes
void segregateOddEven(Node** head) {
    if (*head == nullptr) return;

    Node* end = *head;
    Node* prev = nullptr;
    Node* curr = *head;

    // Get pointer to the last node
    while (end->next != nullptr)
        end = end->next;

    Node* new_end = end;

    // Consider all odd nodes before the first even node and move them to end
    while (curr->data % 2 != 0 && curr != end) {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = nullptr;
        new_end = new_end->next;
    }

    // Do following steps only if there is any even node
    if (curr->data % 2 == 0) {
        *head = curr;

        while (curr != end) {
            if (curr->data % 2 == 0) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr->next = nullptr;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    } else prev = curr;

    // If there are more than 1 odd nodes and end of original list is odd then move this node to end to maintain same order of odd numbers in modified list
    if (new_end != end && (end->data) % 2 != 0) {
        prev->next = end->next;
        end->next = nullptr;
        new_end->next = end;
    }
}

int main() {
    Node* head = nullptr;

    // Example usage
    append(&head, 17);
    append(&head, 15);
    append(&head, 8);
    append(&head, 12);
    append(&head, 10);
    append(&head, 5);
    append(&head, 4);
    append(&head, 1);
    append(&head, 7);
    append(&head, 6);

    cout << "Original List: ";
    display(head);

    segregateOddEven(&head);

    cout << "Modified List: ";
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

#include <iostream>
#include <cstring>

using namespace std;

// Define the contact structure
struct Contact {
    char name[100];
    char mobile[15];
    Contact* next;
};

// Function to create a new contact
Contact* createContact(const char* name, const char* mobile) {
    Contact* newContact = new Contact();
    strcpy(newContact->name, name);
    strcpy(newContact->mobile, mobile);
    newContact->next = nullptr;
    return newContact;
}

// Function to get the length of the contact list
int getLength(Contact* head) {
    int length = 0;
    Contact* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to add a contact at the beginning
void addAtBeg(Contact** head, const char* name, const char* mobile) {
    Contact* newContact = createContact(name, mobile);
    newContact->next = *head;
    *head = newContact;
}

// Function to append a contact at the end
void append(Contact** head, const char* name, const char* mobile) {
    Contact* newContact = createContact(name, mobile);
    if (*head == nullptr) {
        *head = newContact;
        return;
    }
    Contact* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newContact;
}

// Function to add a contact at a specific position
void addAtPOS(Contact** head, const char* name, const char* mobile, int pos) {
    if (pos == 0) {
        addAtBeg(head, name, mobile);
        return;
    }
    Contact* newContact = createContact(name, mobile);
    Contact* temp = *head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    newContact->next = temp->next;
    temp->next = newContact;
}

// Function to display the contact list
void display(Contact* head) {
    Contact* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Mobile: " << temp->mobile << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to display more details of the contact list
void displayMORE(Contact* head) {
    Contact* temp = head;
    while (temp != nullptr) {
        cout << "Address: " << temp << ", Name: " << temp->name << ", Mobile: " << temp->mobile << ", Next: " << temp->next << endl;
        temp = temp->next;
    }
}

// Function to remove the first contact
void removeFirst(Contact** head) {
    if (*head == nullptr) {
        return;
    }
    Contact* temp = *head;
    *head = (*head)->next;
    delete temp;
}

// Function to remove the last contact
void removeLast(Contact** head) {
    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    Contact* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to remove a contact at a specific position
void removePOS(Contact** head, int pos) {
    if (*head == nullptr) {
        return;
    }
    if (pos == 0) {
        removeFirst(head);
        return;
    }
    Contact* temp = *head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    Contact* contactToDelete = temp->next;
    temp->next = temp->next->next;
    delete contactToDelete;
}

int main() {
    Contact* head = nullptr;

    // Example usage
    append(&head, "Alice", "1234567890");
    append(&head, "Bob", "0987654321");
    addAtBeg(&head, "Charlie", "1112223333");
    addAtPOS(&head, "David", "4445556666", 2);
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

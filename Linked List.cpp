//1. Singly Linked List (SLL)

//Supports: Create, Display, Insert (begin/end), Delete (begin/end), Reverse.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertAtBegin(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void deleteAtBegin() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void display() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List empty\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverseList() {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int ch, val;
    do {
        cout << "\n1.Insert Begin 2.Insert End 3.Delete Begin 4.Delete End 5.Display 6.Reverse 7.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBegin(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3: deleteAtBegin(); break;
            case 4: deleteAtEnd(); break;
            case 5: display(); break;
            case 6: reverseList(); break;
        }
    } while (ch != 7);
}

// 2. Doubly Linked List (DLL)

//Supports: Insert (begin/end), Delete (begin/end), Display forward/backward.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtBegin(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void deleteAtBegin() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    delete temp;
}

void displayForward() {
    Node* temp = head;
    if (!temp) { cout << "List empty\n"; return; }
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void displayBackward() {
    if (head == NULL) { cout << "List empty\n"; return; }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    int ch, val;
    do {
        cout << "\n1.Insert Begin 2.Insert End 3.Delete Begin 4.Delete End 5.Display Fwd 6.Display Rev 7.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBegin(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3: deleteAtBegin(); break;
            case 4: deleteAtEnd(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
        }
    } while (ch != 7);
}
//SINGLY LINKED LIST – Advanced (Tricky) Programs
//Search an element
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void search(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found\n";
}

int main() {
    insert(10); insert(20); insert(30);
    int x; cout << "Enter element to search: "; cin >> x;
    search(x);
}

//Find middle element (slow/fast pointer)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void findMiddle() {
    Node *slow = head, *fast = head;
    if (head == NULL) { cout << "List empty\n"; return; }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
}

int main() {
    insert(50); insert(40); insert(30); insert(20); insert(10);
    findMiddle();
}

// Check if linked list is palindrome
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome() {
    if (head == NULL || head->next == NULL) return true;
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = reverse(slow->next);
    Node* firstHalf = head;
    Node* temp = secondHalf;

    bool palin = true;
    while (temp != NULL) {
        if (firstHalf->data != temp->data) {
            palin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    slow->next = reverse(secondHalf);
    return palin;
}

int main() {
    insert(1); insert(2); insert(2); insert(1);
    if (isPalindrome()) cout << "Palindrome\n";
    else cout << "Not Palindrome\n";
}

//Remove duplicates from sorted list
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void removeDuplicates() {
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;
            curr->next = curr->next->next;
            delete dup;
        } else curr = curr->next;
    }
}

void display() {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    insert(3); insert(3); insert(2); insert(1); insert(1);
    cout << "Before: "; display();
    removeDuplicates();
    cout << "After: "; display();
}

// Find nth node from end
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void nthFromEnd(int n) {
    Node *mainPtr = head, *refPtr = head;
    int count = 0;
    while (count < n) {
        if (refPtr == NULL) { cout << "N larger than length\n"; return; }
        refPtr = refPtr->next;
        count++;
    }
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }
    cout << n << "th node from end: " << mainPtr->data << endl;
}

int main() {
    insert(10); insert(20); insert(30); insert(40); insert(50);
    nthFromEnd(2);
}

// Concatenate two linked lists
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

Node* insert(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* concat(Node* h1, Node* h2) {
    if (h1 == NULL) return h2;
    Node* temp = h1;
    while (temp->next) temp = temp->next;
    temp->next = h2;
    return h1;
}

int main() {
    Node* list1 = NULL; Node* list2 = NULL;
    list1 = insert(list1, 1); list1 = insert(list1, 2);
    list2 = insert(list2, 3); list2 = insert(list2, 4);
    Node* merged = concat(list1, list2);
    display(merged);
}

// DOUBLY LINKED LIST – Tricky
// Reverse a doubly linked list
#include <iostream>
using namespace std;

struct Node { int data; Node* prev; Node* next; };
Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val; newNode->next = NULL;
    if (head == NULL) { newNode->prev = NULL; head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode; newNode->prev = temp;
}

void reverseDLL() {
    Node *temp = NULL, *curr = head;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}

void display() {
    Node* temp = head;
    while (temp) { cout << temp->data << " <-> "; temp = temp->next; }
    cout << "NULL\n";
}

int main() {
    insertEnd(1); insertEnd(2); insertEnd(3);
    cout << "Before: "; display();
    reverseDLL();
    cout << "After: "; display();
}

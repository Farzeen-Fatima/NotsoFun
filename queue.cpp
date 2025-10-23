// Queue (using Array)

//Supports: Enqueue, Dequeue, Display.

#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1)
        cout << "Queue Overflow\n";
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else
        cout << "Deleted: " << queue[front++] << endl;
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main() {
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);
}
QUEUE (using Array) – Tricky
1?? Circular Queue
#include <iostream>
using namespace std;
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front)
        cout << "Queue Full\n";
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        cq[rear] = val;
    }
}

void dequeue() {
    if (front == -1)
        cout << "Queue Empty\n";
    else {
        cout << "Deleted: " << cq[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) { cout << "Queue Empty\n"; return; }
    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50); enqueue(60);
    display();
}

//reverse a queue using stack
#include <iostream>
using namespace std;
#define SIZE 5

int queue[SIZE], stack[SIZE];
int front = -1, rear = -1, top = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) cout << "Queue Full\n";
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

void reverseQueue() {
    if (front == -1) { cout << "Queue Empty\n"; return; }
    for (int i = front; i <= rear; i++)
        push(queue[i]);
    front = 0; rear = -1;
    while (top != -1)
        queue[++rear] = pop();
}

void display() {
    if (front == -1) { cout << "Empty\n"; return; }
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main() {
    enqueue(1); enqueue(2); enqueue(3); enqueue(4);
    cout << "Before: "; display();
    reverseQueue();
    cout << "After: "; display();
}
//Queue using Linked List
struct QNode {
    int data;
    QNode* next;
};
QNode *frontLL = NULL, *rearLL = NULL;

void enqueueLL(int val) {
    QNode* newNode = new QNode();
    newNode->data = val;
    newNode->next = NULL;
    if (rearLL == NULL) frontLL = rearLL = newNode;
    else {
        rearLL->next = newNode;
        rearLL = newNode;
    }
}

void dequeueLL() {
    if (frontLL == NULL) { cout << "Underflow\n"; return; }
    QNode* temp = frontLL;
    frontLL = frontLL->next;
    if (frontLL == NULL) rearLL = NULL;
    delete temp;
}

void displayQueueLL() {
    QNode* temp = frontLL;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Queue – Tricky Problems
//a) Circular Queue Using Array
#define MAXQ 5
int cq[MAXQ];
int front = -1, rear = -1;

void enqueueC(int val) {
    if ((rear + 1) % MAXQ == front) cout << "Overflow\n";
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAXQ;
        cq[rear] = val;
    }
}

void dequeueC() {
    if (front == -1) cout << "Underflow\n";
    else if (front == rear) front = rear = -1;
    else front = (front + 1) % MAXQ;
}

void displayC() {
    if (front == -1) { cout << "Empty\n"; return; }
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAXQ;
    }
    cout << endl;
}

// b) Priority Queue (Simple Array-Based)
struct PQueue {
    int data;
    int priority;
};

PQueue pq[10];
int sizePQ = 0;

void enqueueP(int val, int pr) {
    pq[sizePQ].data = val;
    pq[sizePQ].priority = pr;
    sizePQ++;
}

void dequeueP() {
    if (sizePQ == 0) { cout << "Empty\n"; return; }
    int highest = 0;
    for (int i = 1; i < sizePQ; i++)
        if (pq[i].priority < pq[highest].priority)
            highest = i;
    cout << "Dequeued: " << pq[highest].data << endl;
    for (int i = highest; i < sizePQ - 1; i++)
        pq[i] = pq[i + 1];
    sizePQ--;
}
//Queue – Bonus/Tricky Programs
//Reverse a Queue Using Recursion
struct NodeQ {
    int data;
    NodeQ* next;
};

NodeQ* frontQ = NULL;
NodeQ* rearQ = NULL;

void enqueueQRec(int val) {
    NodeQ* newNode = new NodeQ();
    newNode->data = val;
    newNode->next = NULL;
    if (!rearQ) frontQ = rearQ = newNode;
    else {
        rearQ->next = newNode;
        rearQ = newNode;
    }
}

int dequeueQRec() {
    if (!frontQ) return -1;
    NodeQ* temp = frontQ;
    int val = temp->data;
    frontQ = frontQ->next;
    if (!frontQ) rearQ = NULL;
    delete temp;
    return val;
}

void reverseQueueRec() {
    if (!frontQ) return;
    int data = dequeueQRec();
    reverseQueueRec();
    enqueueQRec(data);
}

// Implement Queue Using Stack (Alternative Version)
#define SIZE2 10
int sA[SIZE2], sB[SIZE2];
int topA = -1, topB = -1;

void pushA(int val) { sA[++topA] = val; }
int popA() { return sA[topA--]; }
void pushB(int val) { sB[++topB] = val; }
int popB() { return sB[topB--]; }

void enqueueS(int val) { pushA(val); }

int dequeueS() {
    if (topA == -1 && topB == -1) { cout << "Empty\n"; return -1; }
    if (topB == -1) while (topA != -1) pushB(popA());
    return popB();
}

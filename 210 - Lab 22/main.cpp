// 210 - Lab 22 - Leah Balakrishnan

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;
    
public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
    
    //destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    // node is deleted by value ( i changed it from delete_node to delete_val)
    void delete_val(int value) {
        if (!head) return; // Empty list
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) return; // Value not found
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }
        delete temp;
    }
    
    // node is deleted by position
    void delete_pos(int position) {
        if (position < 0 || !head) return; // empty list
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
        if (!temp) return; // out of range for position
        
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; // delete head
        if (temp ->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; // delete tail
        
        delete temp;
    }
    
    // head node will be deleted
    void pop_front() {
        if (!head) return; // empty list
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }
    
    // tail node will also be deleted
    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }
    
    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);

    cout << "Initial List Forward: ";
    list.print();
    cout << "Initial List Backward: ";
    list.print_reverse();
    
    // this will delete by position
    cout << "Deleting node at position 2." << endl;
    list.delete_pos(2);
    list.print();
    
    // This tests the pop_front
    cout << "Popping the front." << endl;
    list.pop_front();
    list.print();
    
    // This will test the pop_back
    cout << "Popping back." << endl;
    list.pop_back();
    list.print();
    
    cout <<

    return 0;
}

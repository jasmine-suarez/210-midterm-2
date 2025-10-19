// COMSC-210 | Midterm 2 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        string name;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            name = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    /*
    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(string value) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->name != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }
    */

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(string v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(string v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << "        " << current->name << endl;
            current = current->next;
        }
        cout << endl;
    }

    /*
    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->name << " ";
            current = current->prev;
        }
        cout << endl;
    }
    */
};

int main() {
    srand(time(0));

    vector<string> names;
    ifstream fin;
    fin.open("names.txt");
    if (fin.good()) {
        string name;
        while (fin >> name)
            names.push_back(name);
        fin.close();
    }
    else
        cout << "File not found.\n";

    DoublyLinkedList line;

    // store opens, first 5 customers in line
    cout << "Store opens:\n";
    for (int i = 0; i < 5; i++) {
        string newName = names[rand() % names.size()];
        line.push_back(newName);
        cout << "    " << newName << " joins the line\n";
    }
    cout << "    Resulting line:\n";
    line.print();

    // simulation starts
    for (int minute = 2; minute <= 20; minute++) {
        cout << "Time step #" << minute << ":\n";
        int prob;

        // event 1, customer is served
        prob = rand() % 100 + 1; // returns random number 1- 100
        // if probability is <=40 , function happens
        if (prob <= 40) {
            cout << "    " << " is served\n";
        }

        // event 2, customer joins line
        prob = rand() % 100 + 1;
        if (prob <= 60) {
            cout << "    " << " joined the line\n";
        }

        // event 3, customer at end of line leaves
        prob = rand() % 100 + 1;
        if (prob <= 20) {
            cout << "    " << " (at the rear) left the line\n";
        }


        // event 4, any particular customer leaves the line
        prob = rand() % 100 + 1;
        if (prob)


        // event 5, VIP customer joins the front of the line
        prob = rand() % 100 + 1;


    }
    
    return 0;
}
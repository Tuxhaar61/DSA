
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class list {
    Node* head;
    Node* tail;

    // Helper function for recursive search
    int helper(Node* temp, int key) {
        if (temp == nullptr) {
            return -1;
        }

        if (temp->data == key) {
            return 0;
        }

        int idx = helper(temp->next, key);

        if (idx == -1) {
            return -1;
        }

        return idx + 1;
    }

public:
    list() {
        head = nullptr;
        tail = nullptr;
    }

    // Free all nodes
    ~list() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Insert at a zero-based position
    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "LL is empty\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    int searchItr(int key) {
        Node* temp = head;
        int idx = 0;

        while (temp != nullptr) {
            if (temp->data == key) {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    int searchRec(int key) {
        return helper(head, key);
    }

    void reverse() {
        Node* curr = head;
        Node* prev = nullptr;

        tail = head;

        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    int size() {
        int sz = 0;
        Node* temp = head;

        while (temp != nullptr) {
            sz++;
            temp = temp->next;
        }

        return sz;
    }

    // Remove the nth node from the end (n starts at 1)
    void removeNth(int n) {
        int sz = size();

        if (n <= 0 || n > sz) {
            cout << "Invalid n\n";
            return;
        }

        if (n == sz) {
            pop_front();
            return;
        }

        Node* prev = head;

        for (int i = 1; i < sz - n; i++) {
            prev = prev->next;
        }

        Node* toDel = prev->next;
        prev->next = toDel->next;

        if (toDel == tail) {
            tail = prev;
        }

        delete toDel;
    }

    bool isCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "Cycle exists\n";
                return true;
            }
        }

        cout << "Cycle does not exist\n";
        return false;
    }
    void removeCycle(Node* head){
        Node *slow = head;
        Node *fast = head;
        bool isCycle = false;
        while(fast!=NULL && fast->next!=NULL){
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast){
            cout<<"cycle exists\n";
            isCycle = true;
            break;
           }

        }
        if(!isCycle){
            cout<<"cycle doesn't exists\n";
            return;
        }
        slow = head;
        if(slow==fast){//special case ; tail->head
          while(fast->next!=slow){
            fast=fast->next;
          }
          fast->next = NULL;//remove cycle
        }else {
            Node* prev = fast;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
                prev = fast;
            }
            prev->next = NULL;//remove cycle 
        }
    }
    Node* splitAtMid(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL;//split at middle
        }
        return slow;//slow = rightHead;
    }
    void mergeSort(Node* head){
        if(head==NULL|| head->next == NULL)
{
    return;
}        Node* rightHead = splitAtMid(head);
        mergeSort(head);//left sort
        mergeSort(rightHead);//right sort
        merge(head,rightHead);
    }
};

int main() {
    list ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    ll.push_back(4);
    ll.push_back(5);

    ll.insert(100, 2);
    ll.printList();

    ll.pop_front();
    ll.printList();

    cout << "Iterative search index: "
         << ll.searchItr(2) << endl;

    cout << "Recursive search index: "
         << ll.searchRec(4) << endl;

    ll.reverse();
    ll.printList();

    ll.removeNth(2);
    ll.printList();

    cout << "Size: " << ll.size() << endl;

    ll.isCycle();
    return 0;
}


class MyLinkedList {
public:

    // Node
    class Node {
    public:
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;

    // Constructor
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Get value at index
    int get(int index) {

        if (index < 0 || index >= size)
            return -1;

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    // Add at head
    void addAtHead(int val) {

        Node* t = new Node(val);

        if (size == 0) {
            head = tail = t;
        }
        else {
            t->next = head;
            head = t;
        }

        size++;
    }

    // Add at tail
    void addAtTail(int val) {

        Node* t = new Node(val);

        if (size == 0) {
            head = tail = t;
        }
        else {
            tail->next = t;
            tail = t;
        }

        size++;
    }

    // Add before index
    void addAtIndex(int index, int val) {

        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* t = new Node(val);
        Node* temp = head;

        // Find node before index
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        t->next = temp->next;
        temp->next = t;

        size++;
    }

    // Delete at index
    void deleteAtIndex(int index) {

        if (index < 0 || index >= size)
            return;

        // Delete head
        if (index == 0) {

            Node* temp = head;

            head = head->next;

            delete temp;

            size--;

            if (size == 0)
                tail = NULL;

            return;
        }

        // Find node before index
        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;

        temp->next = toDelete->next;

        // If deleting tail
        if (toDelete == tail)
            tail = temp;

        delete toDelete;

        size--;
    }
};

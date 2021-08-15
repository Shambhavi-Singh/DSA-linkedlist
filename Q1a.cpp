#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    //constructor
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    //constructor
    LinkedList()
    {
        head = NULL;
    }
    void reverseLinkedList()
    {
        Node *current = head;
        Node *pred = NULL;
        Node *succ = NULL;
        while (current != NULL)
        {
            succ = current->next;
            current->next = pred;
            pred = current;
            current = succ;
        }
        head = pred;
    }
    void push(int add)
    {
        Node *latest = new Node(add);
        latest->next = head;
        head = latest;
    }
    void printLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// reverseLinkedList()
// {
// }

int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    cout << "Original Linked List" << endl;
    ll.printLinkedList();
    ll.reverseLinkedList();
    cout << "Linked List after reversing" << endl;
    ll.printLinkedList();
    return 0;
}
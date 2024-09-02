#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
 
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void InsertatHead(Node *&head, int val)
{

    Node *n = new Node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void InsertatTail(Node *&head, int val)
{
    if (head == NULL)
    {
        InsertatHead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void DeleteatHead(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void Delete(Node *&head, int pos)
{
    if (pos == 1)
    {
        DeleteatHead(head);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void Reverse(Node *&head, Node *&tail)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nextptr = curr->next;
        curr->next = curr->prev;
        curr->prev = nextptr;
        curr = nextptr;
    }
    Node *newhead = tail;
    tail = head;
    head = newhead;
}

void Display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;

    InsertatTail(head, 2);
    Display(head);

    InsertatTail(head, 3);
    Display(head);

    InsertatTail(head, 4);
    Display(head);

    InsertatTail(head, 9);
    Display(head);

    InsertatTail(head, 7);
    Display(head);

    InsertatTail(head, 8);
    Display(head);

    InsertatHead(head, 45);
    Display(head);

    Delete(head, 3);
    Display(head);

    Delete(head, 1);
    Display(head);

    Node n;
    Reverse(n.head,n.tail);
    Display(head);
    return 0;
}
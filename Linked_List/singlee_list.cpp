#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void InsertatHead(Node *&head, int val)
{

    Node *new_node = new Node(val);

    new_node->next = head;
    head = new_node;
}

void InsertatTail(Node *&head, int val)
{
    Node *new_nodde = new Node(val);

    if (head == NULL)
    {
        head = new_nodde;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_nodde;
}

void InsertatPosition(Node *&head, int val, int posi)
{
    if (posi == 0)
    {
        InsertatHead(head, val);
        return;
    }
    else
    {
        Node *new_noode = new Node(val);
        Node *temp = head;

        int current = 0;
        while (current != posi - 1)
        {
            temp = temp->next;
            current++;
        }
        new_noode->next = temp->next;
        temp->next = new_noode;
    }
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

int Search(Node *head, int key)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data != key)
        {
            count++;
        }

        else if (temp->data == key)
        {
            return count;
        }
        temp = temp->next;
    }
    return -1;
}

void Delete(Node *&head, int val)
{
    Node *temp = head;
    if (head->data == val)
    {
        head = head->next;
        delete temp;
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

Node *Reverse(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newhead = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

Node *ReverseK(Node *&head, int k)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;

    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = ReverseK(nextptr, k);
    }
    return prevptr;
}

Node *ReverseI(Node *&head)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

int main()
{
    Node *head = NULL;
    InsertatTail(head, 1);
    Display(head);

    InsertatTail(head, 2);
    Display(head);

    InsertatHead(head, 3);
    Display(head);

    InsertatHead(head, 9);
    Display(head);

    InsertatPosition(head, 4, 2);
    Display(head);

    cout << Search(head, 4) << endl;

    Delete(head, 2);
    Display(head);

    // Node *newhead = Reverse(head);
    // Display(newhead);

    // Node *newhead = ReverseI(head);
    // Display(newhead);

    int k = 2;
    Node *newh = ReverseK(head, k);
    Display(newh);
    return 0;
}
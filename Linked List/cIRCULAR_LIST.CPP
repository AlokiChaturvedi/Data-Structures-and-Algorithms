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
    Node *n = new Node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void Insertattail(Node *&head, int val)
{
    if (head == NULL)
    {
        InsertatHead(head, val);
        return;
    }

    Node *n = new Node(val);
    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteAthead(Node *&head)
{
    Node *temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node*todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}
void deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAthead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main()
{
    Node *head = NULL;

    Insertattail(head, 6);
    Insertattail(head, 7);
    Insertattail(head, 8);
    Insertattail(head, 9);
    display(head);

    InsertatHead(head, 1);
    display(head);
    

    deletion(head,5);
    display(head);
}
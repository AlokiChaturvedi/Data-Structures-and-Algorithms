#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void InsertatHead(Node *&head, int val)
{

    Node *new_node = new Node(val);

    new_node->next = head;
    head = new_node;
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
        temp->next=new_noode;
    }
}

void InsertatTail(Node *&head, int val)
{
    Node *new_nodde = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_nodde;
}

void Display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DeleteatHead(Node* &head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

void DeleteatAlternate(Node* &head){

    Node* curr= head;
    while(curr!=NULL && curr->next!=NULL){
        Node* temp=curr->next;
        curr->next= curr->next->next;
         free(temp);
         curr=curr->next;
    }
}

void UpdatePosition(Node* &head, int val, int posi){

    Node* temp= head;
    int curr=0;

    while (curr!=posi)
    {
        temp=temp->next;
        curr++;
    }
     temp->val=val;
}

int main()
{
    Node *head = NULL;
    Display(head);

    InsertatHead(head, 2);
    Display(head);

    InsertatHead(head, 4);
    Display(head);

    InsertatTail(head, 3);
    Display(head);

    InsertatPosition(head, 1, 2);
    Display(head);

    InsertatTail(head, 5);
    Display(head);

    DeleteatAlternate(head);
    Display(head);

    DeleteatHead(head);
    Display(head);

    UpdatePosition(head,6,1);
    Display(head);

    return 0;
}
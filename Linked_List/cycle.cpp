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

void MakeCycle(Node *&head, int pos)
{

    Node *temp = head;
    Node *StartNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            StartNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = StartNode;
}

bool DetectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void DeleteCycle(Node * &head)
{

    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);

    fast=head;

    while (slow->next!=fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next=NULL;
}


    int main()
    {
        Node *head = NULL;
        Display(head);

        InsertatHead(head, 2);
        Display(head);

        InsertatHead(head, 4);
        Display(head);

        InsertatHead(head, 2);
        Display(head);

        InsertatHead(head, 8);
        Display(head);

        MakeCycle(head, 2);
        // Display(head);

        cout << endl
             << DetectCycle(head) << endl;
        // Display(head);

        DeleteCycle(head);
        Display(head);
        return 0;
    }
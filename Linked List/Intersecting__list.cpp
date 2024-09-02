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

void InsertatHead1(Node *&head1, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head1;
    head1 = new_node;
}

void InsertatHead2(Node *&head2, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head2;
    head2 = new_node;
}

void Display1(Node *&head1)
{
    Node *temp = head1;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Display2(Node *&head2)
{
    Node *temp = head2;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLenght(Node *&head)
{
    Node *temp = head;
    int lenght = 0;

    while (temp != NULL)
    {
        lenght++;
        temp = temp->next;
    }
    return lenght;
}

Node* MoveheadbyK(Node *head, int k)
{
    Node *ptr = head;
    while (k--)
    {
        ptr = ptr->next;
    }
    return ptr;
}

Node *getIntersection(Node *head1, Node *head2)
{
    int l1 = getLenght(head1);
    int l2 = getLenght(head2);

    Node * ptr1, ptr2;
    if (l1 > l2)
    {
        int k = l1 - l2;
        ptr1 = MoveheadbyK(head1, k);
        ptr2 = head2;
    }
    else
    {
        int k = l2 - l1;
        ptr2 = MoveheadbyK(head2, k);
        ptr1 = head1;
    }

    while (ptr1)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main()
{
    Node *head1 = NULL;

    Node *head2 = NULL;
    cout << "First Linked List is: ";
    InsertatHead1(head1, 5);
    // Display1(head1);
    InsertatHead1(head1, 6);
    // Display1(head1);
    InsertatHead1(head1, 4);
    // Display1(head1);
    InsertatHead1(head1, 3);
    // Display1(head1);
    InsertatHead1(head1, 7);
    // Display1(head1);
    InsertatHead1(head1, 1);
    Display1(head1);

    cout << "Second Llinked list is: ";
    InsertatHead1(head2, 8);
    // Display1(head1);
    InsertatHead1(head2, 9);
    // Display1(head1);
    InsertatHead1(head2, 7);
    // Display1(head1);
    InsertatHead1(head2, 1);
    Display1(head2);
}
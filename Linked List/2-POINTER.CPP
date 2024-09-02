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

bool CheckEqual(Node*&head1, Node*&head2){
    while(head1!=NULL && head2!=NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
int main()
{
    Node* head1=NULL;

    Node* head2=NULL;
    cout<<"First Linked List is: ";
    InsertatHead1(head1,5);
    //Display1(head1);
    InsertatHead1(head1,6);
   // Display1(head1);
    InsertatHead1(head1,7);
    //Display1(head1);
    InsertatHead1(head1,1);
    Display1(head1);

    cout<<"Second Llinked list is: ";
    InsertatHead1(head2,5);
    //Display1(head1);
    InsertatHead1(head2,6);
   // Display1(head1);
    InsertatHead1(head2,7);
    //Display1(head1);
    InsertatHead1(head2,1);
    Display1(head2);

    cout<<CheckEqual(head1,head2)<<endl;
    return 0;
}
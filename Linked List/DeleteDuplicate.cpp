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

void DeleteDuplicate(Node* &head){

    Node* curr= head;
    while (curr)
    {
        while(curr->next && curr->data==curr->next->data){
            Node* temp= curr->next;
            curr->next=curr->next->next;
            free(temp);
        }
        curr=curr->next;
    }
        
}

    int main()
    {
        Node *head = NULL;
        Display(head);

        InsertatHead(head, 2);
        Display(head);

        InsertatHead(head, 4);
        Display(head);
        
        InsertatHead(head, 4);
        Display(head);

        InsertatHead(head, 2);
        Display(head);

        InsertatHead(head, 8);
        Display(head);
        
        InsertatHead(head, 8);
        Display(head);
        
        InsertatHead(head, 3);
        Display(head);

        DeleteDuplicate(head);
        Display(head);

        return 0;
    }
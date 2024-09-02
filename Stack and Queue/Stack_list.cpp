#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d)
    {
        this->data = d;
        this->next == NULL;
    }
};

class Stack
{
    Node *head;
    int capacity;
    int currSize;

public:
    Stack(int c)
    {
        this->capacity = c;
        this->currSize = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }

    bool isFull()
    {
        return this->currSize == this->capacity;
    }

    void push(int data)
    {
        if (this->capacity == this->currSize)
        {
            cout << "Overflow" << endl;
            return;
        }

        Node *new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
        this->currSize++;
    }

    void pop()
    {
        if (this->head == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        Node *new_head = this->head->next;
        this->head->next = NULL;
        delete this->head;
        this->head = new_head;
    }

    int get_top()
    {
        if (this->head == NULL)
        {
            cout << "Underflow" << endl;
            return INT16_MIN;
        }
        return this->head->data;
    }

    int size(){
        Node *temp=this->head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.get_top() << endl;
    st.push(5);
    cout << st.get_top() << endl;
    st.push(9);
    st.push(8);
    cout << st.get_top() << endl;
    st.pop();
    cout << st.get_top() << endl;
    st.pop();
    cout << st.get_top() << endl;

    cout<<st.size()<<endl;

    return 0;
}
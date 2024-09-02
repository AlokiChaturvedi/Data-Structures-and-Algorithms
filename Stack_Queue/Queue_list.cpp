#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next == NULL;
    }
};

class Queue
{
public:
    Node *head;
    Node *tail;
    int size;

    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue()
    {
        if (this->head == NULL)
        {
            return;
        }
        else
        {
            Node *oldhead = this->head;
            Node *newhead = this->head->next;
            this->head = newhead;
            if (this->head == NULL)
            {
                this->tail = NULL;
            }
            oldhead->next = NULL;
            delete oldhead;
            this->size--;
        }
    }

    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }

    int front()
    {
        if (this->head == NULL)
        {
            return -1;
        }
        return this->head->data;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(10);

    while (not q.isEmpty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }
    return 0;
}

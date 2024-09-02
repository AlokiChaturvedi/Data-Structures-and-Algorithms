#include <iostream>
using namespace std;

class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        this->top--;
    }

    int get_top()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return INT16_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty(){
        return this->top==-1;
    }

    int size(){
        return this->top+1;
    }

    bool isFull(){
        return this->top == this->capacity-1;
    }

};

int main(){

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.get_top()<<endl;
    st.push(5);
    cout<<st.get_top()<<endl;
    st.push(9);
    st.push(8);
    cout<<st.get_top()<<endl;
    st.pop();
    cout<<st.get_top()<<endl;
    st.pop();
    cout<<st.get_top()<<endl;

    cout<<st.size()<<endl;
    

    return 0;
}
#include<bits/stdc++.h>

using namespace std;
 
// Define the default capacity of the stack
#define SIZE 100
 
 // A class to represent a stack
 class Stack
 {
    int *arr;
    int top;
    int capacity;
    public:
        Stack(int size = SIZE);
        ~Stack();

        void push(int);
        int pop();
        int peek();

        int size();
        bool isEmpty();
        bool isFull();
 };

 //Constructor to initialize the stack
 Stack::Stack(int size)
 {
    arr = new int[size];
    capacity = size;
    top = -1;
 }

 //Destructor to free memory allocated to the stack
 Stack::~Stack(){
    delete[] arr;
 }

 // Utility function to add an element `x` to the stack
 void Stack::push(int x)
 {
    if(isFull())
    {
        cout<<"Overflow\nProgram Terminated";
        exit(EXIT_FAILURE);
    }
    cout<<"Inserting "<<x<<endl;
    arr[++top]=x;
 }

 int Stack::pop()
 {
    if(isEmpty()){
        cout<<"Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout<<"Removing "<<peek()<<endl;

    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
 }

 //Utility function to return the top of the stack
 int Stack::peek(){
    if(!isEmpty()){
        return arr[top];
    }else{
        exit(EXIT_FAILURE);
    }
 }


 int Stack::size(){
    return top+1;
 }

 // Utility function to check if the stack is empty or not
 bool Stack::isEmpty() {
    return top==-1;    //or return size() == capacity;
 }

bool Stack::isFull(){
    return top==capacity-1;
}


int main()
{
    Stack pt(3);

    pt.push(1);
    pt.push(2);

    pt.pop();
    pt.pop();

    pt.push(3);

    cout<<"The top element is "<<pt.peek()<<endl;
    cout<<"The stack size is "<<pt.size()<<endl;

    pt.pop();

    if(pt.isEmpty()){
        cout<< "The stack is empty\n";
    }
    else{
        cout<<"The stack is not empty\n";
    }

    return 0;
}




 



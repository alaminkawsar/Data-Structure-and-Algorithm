#include<bits/stdc++.h>

using namespace std;
 
// Define the default capacity of the queue
#define SIZE 100
 
 // A class to represent a queue
 class Queue
 {
    int *arr;
    int top;
    int iterate;
    int capacity;
    public:
        Queue(int size = SIZE);
        ~Queue();

        void push(int);
        int pop();
        int peek();

        int size();
        bool isOver();
 };

 //Constructor to initialize the stack
 Queue::Queue(int size)
 {
    arr = new int[size];
    capacity = size;
    iterate=0;
    top = -1;
 }

 //Destructor to free memory allocated to the stack
 Queue::~Queue(){
    delete[] arr;
 }

 // Utility function to add an element `x` to the stack
 void Queue::push(int x)
 {
    
    cout<<"Inserting "<<x<<endl;
    arr[++top]=x;
 }

 int Queue::pop()
 {
    if(isOver()){
        cout<<"Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout<<"Removing "<<peek()<<endl;

    // increase iteration by one and (optionally) return the popped element
    return arr[iterate++];
 }

 //Utility function to return the value of the queue
 int Queue::peek(){
    if(!isOver()){
        return arr[iterate];
    }else{
        exit(EXIT_FAILURE);
    }
 }


 int Queue::size(){
    return (top+1-iterate);
 }


bool Queue::isOver(){
    if(iterate>top){
        return true;
    }else return false;
}


int main()
{
    Queue pt(3);

    pt.push(1);
    pt.push(2);

    pt.pop();
    pt.pop();

    pt.push(3);

    cout<<"The the first element is "<<pt.peek()<<endl;
    cout<<"The queue size is "<<pt.size()<<endl;

    pt.pop();


    return 0;
}




 



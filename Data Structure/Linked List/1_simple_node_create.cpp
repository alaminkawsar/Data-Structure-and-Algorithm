#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

struct node{
    int roll;
    node *next;
};

//root node, we will traverse from it
node *root = NULL;

void append(int roll){
    if(root==NULL){
        root = new node();
        root->roll = roll;
        root->next = NULL;
        return;
    }
    node *current_node = root;
    while (current_node->next!=NULL){
        //find the last node
        current_node = current_node->next;
    }
    //create new node and store value
    node *newnode = new node();
    newnode->roll = roll;
    newnode->next = NULL;

    //link the last node with new node
    current_node->next = newnode;
}

void printAll(){
    node *curent_node = root;
    while(curent_node!=NULL){
        printf("Student Roll: %d\n",curent_node->roll);
        curent_node = curent_node->next;
    }
}


int main(){

    append(2);
    append(1);
    append(5);
    append(7);

    printAll();


    return 0;
}
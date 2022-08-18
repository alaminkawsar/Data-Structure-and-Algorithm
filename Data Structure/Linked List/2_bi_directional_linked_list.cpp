/*In this program, we will delete node and append in any position*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

struct node{
    int roll;
    node *next, *prev;
};

//root node, we will traverse from it
node *root = NULL, *tail=NULL;

void append(int roll){

    if(root==NULL){
        root = new node();
        root->roll = roll;
        root->next = NULL;
        root->prev = NULL;
        tail = root;
        return;
    }
    
    //create new node and store value
    node *newnode = new node();
    newnode->roll = roll;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = tail->next;
}


// Delete node from any position by value

void PrinttraverseFromBack(){
    node *current_node=tail;
    while (current_node!=NULL)
    {
        printf("Student Roll From Last %d\n",current_node->roll);
        current_node = current_node->prev;
    }
    
}

void delete_node(int roll){
    node *current_node = root;
    node *previous_node = current_node;
    while (current_node!=NULL and current_node->roll!=roll)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node==NULL){
        printf("Roll Not Found");
        return;
    }
    previous_node->next = current_node->next;
    delete(current_node);

    
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
    append(3);
    append(9);
    append(10);

    printAll();

    printf("\nAfter operation:\n");

    PrinttraverseFromBack();


    return 0;
}
/*In this program, we will delete node and append in any position*/

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


// Delete node from any position by value

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
    delete_node(9);
    printf("\nAfter operation:\n");

    printAll();


    return 0;
}
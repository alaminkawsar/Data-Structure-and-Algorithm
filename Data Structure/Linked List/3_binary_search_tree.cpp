/*In this program, we will delete node and append in any position*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

struct node{
    int val;
    node *right, *left;
    //initialize the node using null
    node(){
        right=NULL;
        left=NULL;
    }
};

//root node, we will traverse from it
node *root=NULL;

void append(int val){
    if(root==NULL){
        root = new node();
        root->val = val;
        return;
    }
    node *current_node = root, *parent;
    while(current_node!=NULL){
        if(current_node->val<=val){
            parent = current_node;
            current_node = current_node->right;
        }else{
            parent = current_node;
            current_node = current_node->left;
        }
    }
    node *newnode = new node();
    newnode->val=val;
    
    if(parent->val<val){
        parent->right=newnode;
    }else parent->left=newnode;

}


// Delete node from any position by value

// void delete_node(int roll){
//     node *current_node = root;
//     node *previous_node = current_node;
//     while (current_node!=NULL and current_node->roll!=roll)
//     {
//         previous_node = current_node;
//         current_node = current_node->next;
//     }
//     if(current_node==NULL){
//         printf("Roll Not Found");
//         return;
//     }
//     previous_node->next = current_node->next;
//     delete(current_node);

    
// }

void print_preorder(node *current){
    if(current==NULL) return;
    cout<<current->val<<endl;
    print_preorder(current->left);
    print_preorder(current->right);
}


int main(){

    append(2);
    append(1);
    append(5);
    append(7);
    append(3);
    append(9);
    append(10);

    print_preorder(root);


    return 0;
}
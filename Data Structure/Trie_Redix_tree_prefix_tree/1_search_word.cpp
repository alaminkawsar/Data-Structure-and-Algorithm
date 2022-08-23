#include<bits/stdc++.h>
using namespace std;

struct node{
    bool endmark;
    node* next[26+1];
    node(){
        endmark = false;
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
    }
};

node* root;

void insert(char* str, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(char* str, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        if(curr->next[id]==NULL){
            return false;
        }
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* curr){
    for(int i=0;i<26;i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //puts("Enter Number of Words");
    root = new node();
    int num_word;
    scanf("%d",&num_word);
    for(int i=1;i<=num_word;i++){
        char str[50];
        scanf("%s",str);
        insert(str, strlen(str));
    }
    //puts("Enter Number of Query");
    int query;
    scanf("%d",&query);
    while(query--){
        char str[50];
        scanf("%s",str);
        if(search(str,strlen(str))){
            puts("Found");
        }else puts("Not Found");
    }
    delete(root);


    return 0;
}


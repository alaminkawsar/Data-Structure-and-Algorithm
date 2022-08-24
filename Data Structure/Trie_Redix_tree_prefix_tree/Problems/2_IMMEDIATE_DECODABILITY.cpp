#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>

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

bool insert(string str, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = str[i]-'0';
        if(curr->next[id]==NULL){
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        if(curr->endmark) return false;
    }
    return curr->endmark = true;
}

bool search(string str, int len){
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
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    vector<string>num;
    int cnt = 1;
    string s;
    while(cin>>s){
        num.push_back(s);
        if(s!="9"){
            continue;
        }

        root = new node();
        int num_word;
        num_word = num.size();
        bool flag=true;
        for(int i=0;i<num_word;i++){
            if(!insert(num[i], num[i].size())){
                flag=false;
                break;
            }
        }
        if(flag){
            printf("Set %d is immediately decodable\n",cnt++);
        }else{
            printf("Set %d is not immediately decodable\n",cnt++);
        }
        num.clear();
        
        delete(root);
    }

    return 0;
}


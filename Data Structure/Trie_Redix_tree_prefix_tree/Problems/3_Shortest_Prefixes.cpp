#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

struct node{
    bool endmark;
    node* next[26+1];
    int cnt;
    node(){
        endmark = false;
        cnt = 0;
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
    }
};

node* root;

void insert(string str, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}

string search(string str, int len){
    node* curr = root;
    string ans="";
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        ans+=str[i];
        if(curr->next[id]==NULL){
            return "FFFFFF";
        }
        curr = curr->next[id];
        if(curr->cnt<=1) return ans;
    }
    if(curr->endmark) return str;
    else return "FFFFFFF";
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
    //freopen("output.txt","w",stdout);

    //puts("Enter Number of Words");
    string s;
    vector<string>words,abrr;
    while(cin>>s){
        words.push_back(s);
    }
    root = new node();
    int num_word=words.size();
    for(int i=0;i<num_word;i++){

        insert(words[i], words[i].size());
    }
    //puts("Enter Number of Query");
    for(int i=0;i<num_word;i++){
        cout<<words[i]<<' '<<search(words[i],words[i].size())<<endl;
    }
    del(root);


    return 0;
}


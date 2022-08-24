#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

struct node{
    bool endmark;
    node* next[13];
    node(){
        endmark = false;
        for(int i=0;i<12;i++){
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
        }else{
            if(i==len-1){
                return false;
            }
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
    for(int i=0;i<12;i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}


void solve(){

    int num_word;
    cin>>num_word;
    vector<string>num;
    string s;
    for(int i=0;i<num_word;i++){
        cin>>s;
        num.push_back(s);
    }
    root = new node();
    bool flag=true;
    for(int i=0;i<num_word;i++){
        if(!insert(num[i], num[i].size())){
            flag=false;
            break;
        }
    }
    if(flag){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
        
    del(root);
    
}

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d: ",++ts);
        solve();
    }

    return 0;
}
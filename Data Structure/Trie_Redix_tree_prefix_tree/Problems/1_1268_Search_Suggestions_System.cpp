#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;


struct node{
    bool endmark;
    node* next[26];
    bool vis[26];
    node(){
        endmark=false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
            vis[i]=false;
        }
    }
};

node* root;
int cnt = 0;

vector<vector<string>>ansList;
vector<string>tempAns;

void dfs(node* root,string ans){
    node* cur = root;
    if(cur->endmark==true){
        cnt++;
        tempAns.push_back(ans);
    }
    if(cnt>=3) return;

    for(int i=0;i<26;i++){
        if(cnt>=3) return;
        if(cur->next[i]!=NULL){
            ans+=('a'+i);
            dfs(cur->next[i], ans);
            ans.pop_back();
        }
    }
}


void insert(string s, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = s[i]-'a';
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr = curr->next[id];
    }
    curr->endmark=true;
}

void search(string s, int len){
    node* curr = root;
    string ans="";
    bool flag = true;
    for(int i=0;i<len;i++){
        int id = s[i]-'a';
        cnt = 0;
        if(curr->next[id]!=NULL and flag){
            ans+=s[i];
            dfs(curr->next[id],ans);
            ansList.push_back(tempAns);
            tempAns.clear();
            //printf("\n");
            curr = curr->next[id];
        }else{
            flag=false;
            ansList.push_back({});
        }
        
    }
}

void del(node* curr){
    for(int i=0;i<26;i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}

void solve()
{
    vector<string>products {"ghij","a","b","bb","c","cc","abcd","abcdef","abcdhi","abcdgf","ij"};
    string searchWord = "idfsdrkljgj";

    sort(products.begin(),products.end());

    root = new node();

    for(int i=0;i<products.size();i++){
        //cout<<products[i]<<endl;
        insert(products[i],products[i].size());
    }
    search(searchWord,searchWord.size());

    for(int i=0;i<ansList.size();i++){
        for(int j=0;j<ansList[i].size();j++){
            cout<<ansList[i][j]<<endl;
        }
        cout<<endl;
    }

    del(root);

    //dfs(root,"");

    // if(search(searchWord,searchWord.size())){
    //     cout<<"Found"<<endl;
    // }else cout<<"Not Found"<<endl;

    
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdin);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

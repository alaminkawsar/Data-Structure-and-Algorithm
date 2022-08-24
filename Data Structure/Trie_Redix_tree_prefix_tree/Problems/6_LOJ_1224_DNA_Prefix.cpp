#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

map<char,int>letter;

using namespace std;

struct node{
    bool endmark;
    node* next[6];
    int cnt;
    node(){
        endmark = false;
        cnt = 0;
        for(int i=0;i<5;i++){
            next[i] = NULL;
        }
    }
};

node* root;

void insert(string str, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = letter[str[i]];
        if(curr->next[id]==NULL){
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->cnt++;
    }
}

ll search(string str, int len){
    node* curr = root;
    ll mx=0,k=0;
    for(int i=0;i<len;i++){
        int id = letter[str[i]];
        curr = curr->next[id];
        k++;
        mx=max(mx,k*1LL*curr->cnt);
    }
    return mx;
}

void del(node* curr){
    for(int i=0;i<5;i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}


void solve(){

    int num_word;
    cin>>num_word;
    string s;
    root = new node();
    vector<string>num;
    for(int i=0;i<num_word;i++){
        cin>>s;
        num.push_back(s);
        insert(s,s.size());
    }
    ll ans = 0;
    for(int i=0;i<num_word;i++){
        ans = max(ans,search(num[i],num[i].size()));
    }
    cout<<ans<<endl;
        
    del(root);
    
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    letter['A']=0;
    letter['C']=1;
    letter['G']=2;
    letter['T']=3;
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d: ",++ts);
        solve();
    }

    return 0;
}
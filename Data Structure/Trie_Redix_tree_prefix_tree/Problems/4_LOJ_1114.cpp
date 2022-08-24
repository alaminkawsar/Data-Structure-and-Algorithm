#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

map<char,int>letter;

struct node{
    bool endmark;
    node* next[55];
    int cnt;
    node(){
        endmark = false;
        cnt = 0;
        for(int i=0;i<54;i++){
            next[i] = NULL;
        }
    }
};

node* root;

void insert(char* str, int len){
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = letter[str[i]];
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    //cout<<curr->cnt+1<<endl;
    if(curr->endmark) curr->cnt++;
    else curr->endmark=true,curr->cnt=1;
}

int search(char* str, int len){
     node* curr = root;
    for(int i=0;i<len;i++){
        int id = letter[str[i]];
        if(curr->next[id]==NULL)
            return false;
        curr = curr->next[id];
    }
    //cout<<curr->cnt+1<<endl;
    return curr->cnt;
}

void del(node* curr){
    for(int i=0;i<54;i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}


void solve()
{
    int num_word;
    scanf("%d",&num_word);
    root = new node();

    char s[105];
    for(int i=0;i<num_word;i++){
        scanf("%s",s);
        int n = strlen(s);
        if(n>2)
            sort(s+1,s+strlen(s)-1);
        //cout<<s<<endl;
        insert(s,strlen(s));
    }
    int m;
    scanf("%d ",&m);
    //getchar();
    char sentence[10005];
    int cc=1;
    while(m--){
        scanf("%[^\n]%*c", sentence);
        char str[105];
        int j=0;
        ll ans=1;
        for(int i=0;sentence[i];i++){
            if(sentence[i]!=' ') str[j++]=sentence[i];
            else if(j>0){
                str[j]='\0';
                if(j>2){
                    sort(str+1,str+j-1);
                }
                //cout<<str<<endl;
                j=0;
                ll k = 1LL*search(str,strlen(str));
                ans*=k;
                
            }
        }
        if(j>0){
            str[j]='\0';
            if(j>2){
                sort(str+1,str+j-1);
            }
            ll k = 1LL*search(str,strlen(str));
            ans*=k;
            //cout<<str<<endl;
        }

        cout<<ans<<endl;
    }
    

    del(root);
    
}
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(int i=0;i<26;i++){
        letter[i+'A']=i;
        letter[i+'a']=i+26;
    }
    
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d:\n",++ts);
        solve();
    }
    return 0;
}

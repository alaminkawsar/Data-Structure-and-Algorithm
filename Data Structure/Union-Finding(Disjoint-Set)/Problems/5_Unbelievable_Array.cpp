//check how many groups are form

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+10;

vector<int>adj[sz];
int parent[sz+5];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
}

void solve(){
    int n = 6, edge=5,query;
    cin>>n>>query;
    
    for(int i=1;i<=sz;i++) make_set(i);
    
    int x,y;
    int ar[n+5];
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }

    while(query--){
        int type,x,y;
        scanf("%d",&type);
        if(type==1){
            scanf("%d%d",&x,&y);
            union_sets(x,y);
        }else{
            scanf("%d",&x);
            printf("%d\n",find_set(ar[x-1]));
        }
    }
    
}

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d:\n",++ts);
        solve();
    }
    return 0;
}


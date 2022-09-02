//check how many groups are form

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+10;

vector<int>adj[sz];
int parent[sz+5],color[sz];

struct q{
    int l;
    int r;
    int c;

}query[sz];

void make_set(int v) {
    parent[v] = -1;
}

int find_set(int v) {
    if (v == parent[v] or parent[v]==-1)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

void solve(){
    int n , q;
    scanf("%d",&n);

    for(int i=0;i<=2*n+5;i++) make_set(i);

    for(int i=0;i<n;i++){
        scanf("%d%d",&query[i].l,&query[i].r);
        parent[query[i].l]=query[i].l;
        parent[query[i].r]=query[i].r;
        query[i].c=i+1;
    }
    
    for(int i=n-1;i>=0;i--){
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;
        for(int v=find_set(l); v<=r; v=find_set(v)){
            color[v]=c;
            //cout<<v<<' '<<v+1<<endl;
            parent[v]=v+1;
        }
    }
    set<int>st;
    for(int i=1;i<=2*n;i++){
        if(parent[i]==-1) continue;
        st.insert(color[i]);
        //cout<<color[i]<<' ';
    }
    //cout<<endl;
    cout<<st.size()<<endl;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d:\n",++ts);
        solve();
    }
    return 0;
}

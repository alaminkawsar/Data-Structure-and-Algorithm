//check how many groups are form

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+10;

vector<int>adj[sz];
int parent[sz+5],khawa[sz+5],id[sz+5];

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
    if (a != b)
        parent[b] = a;
}

void solve(){
    int n = 6, edge=5; 
    scanf("%d%d",&n,&edge);
    for(int i=1;i<=n;i++) make_set(i);
    int x,y,t,fans=0;
    for(int i=0;i<edge;i++){
        scanf("%d%d%d",&t,&x,&y);
        if(x>n or y>n){
            fans++;
            continue;
        }
        if(t==1){

        }else{

        }
    }
    

}
int main()
{
    printf("%d\n",-1%3);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdin);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

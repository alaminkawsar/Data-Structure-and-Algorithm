#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

vector<vector<int>>adj;
vector<bool> vis;

//finding path between u and v
int dfs(int u,int v){
    vis[u]=true;
    for(auto x: adj[u]){
        if(!vis[x]){
            return dfs(x)+1;
        }
    }
    return 1;
}

void solve()
{
    int n; cin>>n;
    adj.clear();
    vis.clear();
    vis.resize(n+1,false);
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
       
    }
    
    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdin);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

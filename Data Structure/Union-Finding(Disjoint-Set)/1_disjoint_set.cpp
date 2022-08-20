//check how many groups are form

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+10;

vector<int>adj[sz];
int parent[sz+5],ran[sz+5],id[sz+5];

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

int main(){
    int n = 6, edge=5; 
    
    for(int i=1;i<=n;i++) make_set(i);
    
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        union_sets(x,y);
    }
    vector<bool>vis(n+5,false);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        x = find_set(i);
        if(vis[x]) continue;
        vis[x]=true;
        cnt++;
    }

    cout<<cnt<<endl;

    


    return 0;
}


//check how many groups are form

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+10;

struct UnionFind {
    std::vector<int> parent;
    UnionFind(int n): parent(n+5){
        for(int i=1;i<=n;i++) parent[i]=i;
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        a = find(a),b = find(b);
        if (a != b) parent[b] = a;
    }
};

int main(){
    int n = 6, edge=5; 
    UnionFind u(n);    
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        u.merge(x,y);
    }
    vector<bool>vis(n+5,false);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        x = u.find(i);
        if(vis[x]) continue;
        vis[x]=true;
        cnt++;
    }

    cout<<cnt<<endl;

    


    return 0;
}


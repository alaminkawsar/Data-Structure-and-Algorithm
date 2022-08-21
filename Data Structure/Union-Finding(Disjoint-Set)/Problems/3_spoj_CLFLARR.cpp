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
    int n , q;
    scanf("%d%d",&n,&q);
    
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&query[i].l,&query[i].r,&query[i].c);
    }
    
    for(int i=0;i<=n+5;i++) make_set(i);
    for(int i=q-1;i>=0;i--){
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;
        for(int v=find_set(l); v<=r; v=find_set(v)){
            color[v]=c;
            parent[v]=v+1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",color[i]);
    }
    
    

    return 0;
}


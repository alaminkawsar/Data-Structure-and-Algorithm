//Problem description: if we join two set, make make parent the first one whoose rank/size is less than the second one.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+10;

struct UnionFind {
    std::vector<int> parent,rank;
    UnionFind(int n): parent(n+5),rank(n+5,1){
        for(int i=1;i<=n;i++) parent[i]=i;
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        a = find(a),b = find(b);
        if (a != b){
            if(rank[a]<rank[b]) swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
        }
    }

};

int main(){
    int n = 7, edge=6;     
    int x,y;
    UnionFind u(n);
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        u.merge(x,y);
    }

    //print every number ranked
    printf("Print their rank\n");
    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,u.rank[i]);

    


    return 0;
}


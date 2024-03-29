//Problem description: if we join two set, make make parent the first one whoose rank/size is less than the second one.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+10;

vector<int>adj[sz];
int parent[sz+5],sized[sz+5],id[sz+5];

void make_set(int v) {
    parent[v] = v;
    sized[v]=1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b){
        if(sized[a]<sized[b])
            swap(a,b);

        parent[b]=a;
        sized[a]+=sized[b];
    }
}

int main(){
    int n = 7, edge=6; 
    
    for(int i=1;i<=n;i++) make_set(i);
    
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        union_sets(x,y);
    }

    //print every number ranked
    printf("Print their rank\n");
    for(int i=1;i<=n;i++)
        printf("indexed %d=%d\n",i,sized[i]);

    


    return 0;

}


//check how many groups are form

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e3+10;

vector<int>adj[sz];
vector<pair<int,int>>ans;
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
    int x = find_set(a);
    int y = find_set(b);
    if (x != y)
        parent[x] = y;
    else
        ans.push_back({a,b});
}

int main(){
    int n = 6, edge=5; 
    cin>>n;
    edge = n-1;
    
    for(int i=1;i<=n;i++) make_set(i);
    
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        union_sets(x,y);
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(parent[i]==i){
            q.push(i);
        }
    }
    vector<pair<int,int>>ansy;
    for(auto x: ans){
        int par = find_set(x.first);
        int y = find_set(q.front());
        q.pop();
        if(par==y){
            int z = find_set(q.front());
            q.pop();
            q.push(y);
            union_sets(par,z);
            ansy.push_back({par,z});
        }else{
            union_sets(par,y);
            ansy.push_back({par,y});
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        printf("%d %d %d %d\n",ans[i].first,ans[i].second,ansy[i].first,ansy[i].second);
    }
    


    return 0;
}


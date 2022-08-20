/* https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center/problem */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+10;

int parent[sz+5],ran[sz+5],id[sz+5];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_parent(int x, int y){
    if(x!=y){
        if(ran[x]>ran[y]){
            parent[y]=x;
            parent[x]=x;
        }else if(ran[x]<ran[y]){
            parent[x]=y;
            parent[y]=y;
        }else{
            if(x>y){
                parent[y]=x;
                parent[x]=x;
            }else parent[x]=y,parent[y]=y;
        }
    }
}

void solve()
{
    int n,q; cin>>n>>q;

    for(int i=0;i<sz;i++){
        parent[i]=i;
    }
    int cnt = n;
    for(int i=0;i<n;i++){
        cin>>id[i];
        ran[id[i]]=cnt--;
    }
    while (q--)
    {
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            x = find_set(x);
            y = find_set(y);
            make_parent(x,y);
            
        }else if(type==2){
            int x;
            cin>>x;
            ran[x]++;
            int y = find_set(x);
            make_parent(x,y);
        }else{
            int x;
            cin>>x;
            int par = find_set(x);
            cout<<par<<endl;
        }
    }


    
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdin);
    int t=1; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
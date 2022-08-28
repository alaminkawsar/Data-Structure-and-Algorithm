#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int tree[sz*4+5];
int ar[sz];

void build(int v, int tl, int tr){
    if(tl==tr){
        tree[v]=ar[tl];
    }else{
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if(l>v){
        return 0;
    }
    if(l==tl and r==tr){
        return tree[v];
    }
    int tm = (tl+tr)/2;
    return max((v*2, tl, tm, l, min(r,tm)),sum(v*2+1, tm+1, r, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        tree[v]=new_val;
    }else{
        int tm = (tl+tr)/2;
        if(pos<=tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
}

void solve()
{

    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

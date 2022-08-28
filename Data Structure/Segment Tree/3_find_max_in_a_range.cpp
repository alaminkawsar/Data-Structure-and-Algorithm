//Finding the maximum and the number of times it appears


#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF (int)INT_MAX
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

pii tree[sz*4+5];
int ar[sz];

pii combine(pii a, pii b){
    if(a.first>b.first)
        return a;
    else if (b.first>a.first)
        return b;
    return pii(a.first,a.second+b.second);
}

void build(int v, int tl, int tr){
    if(tl==tr){
        tree[v]={ar[tl],1};
    }else{
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v]=combine(tree[v*2],tree[v*2+1]);
    }
}

pii getMax(int v, int tl, int tr, int l, int r) {
    if(l>v){
        return pii(-INF,0);
    }
    if(l==tl and r==tr){
        return tree[v];
    }
    int tm = (tl+tr)/2;
    return combine(getMax(v*2, tl, tm, l, min(r,tm)),getMax(v*2+1, tm+1, r, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        tree[v]={new_val,1};
    }else{
        int tm = (tl+tr)/2;
        if(pos<=tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v]=combine(tree[v*2],tree[v*2+1]);
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    build(1,0,n-1);

    
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

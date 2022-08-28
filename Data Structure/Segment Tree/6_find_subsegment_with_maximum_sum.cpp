#include<bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define read(a) scanf("%d",&a)
#define p1(a) cout<<"Check "<<a<<endl;
#define p2(a,b) cout<<"Check "<<a<<' '<<b<<endl;
#define fo(i,n) for (i=0;i<n;i++)
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007

using namespace std;
int const sz=(int)2e5+5;

struct data {
    int sum, pref, suff, ans;
};

data tree[sz*4];
int ar[sz*4];

data combine(data left, data right){
    data res;
    res.sum = left.sum+right.sum;
    res.pref = max(left.pref,left.sum+right.pref);
    res.suff = max(right.suff,right.sum+left.suff);
    res.ans = max(max(left.ans,right.ans), left.suff+right.pref);
    return res;
}

data make_data(int val){
    data res;
    res.sum = val;
    res.pref=res.suff=res.ans=max(0, val);
    return res;
}

void build(int v, int tl, int tr) {
    if(tl==tr) {
        tree[v] = make_data(ar[tl]);
        return;
    }
    int tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1, tr);
    tree[v] = combine(tree[v*2], tree[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int val) {
    if(tl==tr){
        tree[v]=make_data(val);
        return;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm){
        update(v*2, tl, tm ,pos, val);
    }else{
        update(v*2+1, tm+1, tr, pos, val);
    }
    tree[v]=combine(tree[v*2],tree[v*2+1]);
}

data getAnswer(int v, int tl, int tr, int l, int r) {
    if(l>r)
        return make_data(0);
    if(l==tl && r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    return combine(getAnswer(v*2, tl, tm, l, min(r,tm)),
        getAnswer(v*2+1, tm+1, tr, max(l,tm+1), r));

}

void solve()
{
    int n,q; read(n),read(q);
    for(int i=0;i<n;i++) read(ar[i]);

    build(1,0,n-1);
    //update(1,0,n-1,5,1);
    while(q--){
        int x, y;
        cin>>x>>y;
        printf("get_max_sum in a range(%d,%d)=%d\n",x,y,getAnswer(1,0,n-1,x-1,y-1).ans);
    }
    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

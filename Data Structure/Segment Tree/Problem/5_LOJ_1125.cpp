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
    int zero,one,two, prop;
};

data tree[sz*4];

data combine(data left, data right){
    data res;
    res.one=left.one+right.one;
    res.zero = left.zero+right.zero;
    res.two = left.two+right.two;

    return res;
}

data make_data(int val){
    data res;
    res.one = val;
    res.two=val;
    res.zero=0;
    return res;
}

void build(int v, int tl, int tr) {
    if(tl==tr) {
        tree[v].zero=1;
        tree[v].one=0;
        tree[v].two=0;
        tree[v].prop=0;
        return;
    }
    int tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1, tr);
    tree[v] = combine(tree[v*2], tree[v*2+1]);
}

void update(int v, int tl, int tr, int l, int r) {
    if(l>tr or r<tl) return;
    if(l<=tl and tr<=r){
        swap(tree[v].zero,tree[v].two);
        swap(tree[v].one,tree[v].two);
        //p2(tl,tr);
        //p1(tree[v].two);
        return;
    }
    int tm = (tl+tr)/2;
    update(v*2, tl, tm, l, r);
    update(v*2+1, tm+1, tr, l, r);
    tree[v]=combine(tree[v*2],tree[v*2+1]);
}

data getAnswer(int v, int tl, int tr, int l, int r) {
    if(l>tr or r<tl) return make_data(0);
    if(l<=tl and tr<=r){
        return tree[v];
    }
    if(l==tl && r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    return combine(getAnswer(v*2, tl, tm, l, min(r,tm)),
        getAnswer(v*2+1, tm+1, tr, max(l,tm+1), r));

}

void solve()
{
    int n,q; read(n),read(q);
    //for(int i=0;i<n;i++) read(ar[i]);

    build(1,0,n-1);
    //update(1,0,n-1,5,1);
    while(q--){
        int type, x, y;
        read(type);
        read(x);
        read(y);
        //action
        if(type==0){
            update(1,0,n-1,x,y);
        }
        else{
            printf("%d\n",getAnswer(1,0,n-1,x,y).zero);
        }
        data ans = getAnswer(1,0,n-1,0,9);
        printf("HI = %d %d %d\n",ans.zero,ans.one,ans.two);
        
    }
    
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d:\n",++ts);
        solve();
    }
    return 0;
}

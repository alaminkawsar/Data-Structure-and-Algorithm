#include<bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define read(a) scanf("%d",&a)
#define p1(a) cout<<"Check1 "<<a<<endl;
#define p2(a,b) cout<<"Check2 "<<a<<' '<<b<<endl;
#define p3(a,b, c) cout<<"Check3 "<<a<<' '<<b<<' '<<c<<endl;
#define fo(i,n) for (i=0;i<n;i++)
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007

using namespace std;
int const sz=(int)2e5+5;

struct data {
    int zero=0,one=0,two=0, prop=0;
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
    res.zero=val;
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

void update(int v, int tl, int tr, int l, int r, int carry) {

    if((l<=tl and tr<=r) or (l>tr or r<tl)){
        if(l<=tl and tr<=r) carry++;
        int k = carry%3;
        if(k==1){
            swap(tree[v].zero,tree[v].one);
            swap(tree[v].zero,tree[v].two);
        }else if(k==2){
            swap(tree[v].zero,tree[v].two);
            swap(tree[v].zero,tree[v].one);
        }
        tree[v].prop=carry;
        
        // p3(tl,tr,carry);
        // p3(tree[v].zero,tree[v].one,tree[v].two);
        return;
    }
    int tm = (tl+tr)/2;
    int k = tree[v].prop;
    tree[v].prop=0;
    
    update(v*2, tl, tm, l, r, carry+k);
    update(v*2+1, tm+1, tr, l, r, carry+k);
    tree[v]=combine(tree[v*2],tree[v*2+1]);
    //printf("Tree %d=(%d,%d)->(%d %d %d)\n",v,tl,tr,tree[v].zero,tree[v].one,tree[v].two);
}

data getAnswer(int v, int tl, int tr, int l, int r) {
    if(l>tr or r<tl) return make_data(0);
    if(l<=tl and tr<=r){
        return tree[v];
    }
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
            update(1,0,n-1,x,y,0);
        }
        else{
            printf("%d\n",getAnswer(1,0,n-1,x,y).zero);
        }
        //data ans = getAnswer(1,0,n-1,0,9);
        //printf("query(%d %d), zero=%d one=%d two=%d\n",x,y,ans.zero,ans.one,ans.two);
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

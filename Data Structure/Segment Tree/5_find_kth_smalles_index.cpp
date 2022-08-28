//The task is as follows: for a given value x and a range a[l..r] find the smallest i in the range a[l..r] , such that a[i] is greater than x.
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

int g=2*3*5*7*11*13*17*19;

using namespace std;
int const sz=(int)2e5+5;

vi ar(sz),tree(sz*4);

void build(int node, int tl, int tr){
    if(tl==tr){
        tree[node]=ar[tr];
        return;
    }
    int mid=(tl+tr)/2;
    build(node*2,tl,mid);
    build(node*2+1,mid+1,tr);
    tree[node]=max(tree[node*2],tree[node*2+1]);

}

void update(int node, int tl, int tr, int index, int val){
    if(tl==index and index==tr){
        tree[node]=val;
        return;
    }
    if(index<tl or tr<index){
        return;
    }
    int mid=(tl+tr)/2;
    update(node*2,tl,mid,index,val);
    update(node*2+1,mid+1,tr,index, val);
    tree[node]=max(tree[node*2],tree[node*2+1]);

}

int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(tree[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(tree[2*v] > x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}
void solve()
{
    int n,q; read(n),read(q);
    for(int i=0;i<n;i++) read(ar[i]);

    build(1,0,n-1);
    //update(1,0,n-1,5,1);
    while(q--){
        int x, y, val;
        cin>>x>>y>>val;
        printf("getfirst range(%d,%d)=%d\n",x,y,get_first(1,0,n-1,x-1,y-1,val));
    }
    
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

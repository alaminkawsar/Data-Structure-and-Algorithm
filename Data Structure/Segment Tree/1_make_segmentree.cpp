#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int ar[sz+5];
int tree[sz+5];

void init(int node, int b, int e){
    if(b==e){
        tree[node]=ar[b];
        return;
    }
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    init(left,b, mid);
    init(right, mid+1, e);
    
    tree[node]=tree[left]+tree[right];

}

int query(int node,int b,int e, int i, int j){
    if(i<=b and e<=j){
        return tree[node];
    }
    if(e<i or j<b) return 0;
    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return p1+p2;
}

void update(int node,int b,int e, int index, int val){
    if(index<b or index>e) return;

    if(index<=b and index>=e){
        tree[node]=val;
        return;
    }
    
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    update(left,b, mid, index, val);
    update(right, mid+1, e, index, val);
    
    tree[node]=tree[left]+tree[right];
}


void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    init(1, 0, n-1);

    int x,y,type;
    //query 
    for(int i=0;i<q;i++){
        cin>>type>>x>>y;
        if(type==1)
            printf("sum(%d,%d)=%d\n",x,y,query(1,0,n-1,x-1,y-1));
        else{
            update(1,0,n-1,x-1,y);
        }
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

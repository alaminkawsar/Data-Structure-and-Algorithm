#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int ar[sz+5];

struct info{
    int prop,sum;
}tree[sz*3+5];

void init(int node, int b, int e){
    if(b==e){
        tree[node].sum=ar[b];
        return;
    }
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    init(left,b, mid);
    init(right, mid+1, e);
    
    tree[node].sum=tree[left].sum+tree[right].sum;

}

int query(int node,int b,int e, int i, int j, int carry=0){
    if(i<=b and e<=j){
        return tree[node].sum+carry*(e-b+1);
    }
    if(e<i or j<b) return 0;
    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;

    int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);

    return p1+p2;
}

void update(int node,int b,int e, int i,int j, int val){
    if(j<b or i>e) return;

    if(i<=b and e<=j){
        tree[node].sum=(e-b+1)*val;
        tree[node].prop+=val;
        return;
    }
    
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    update(left, b, mid, i, j, val);
    update(right, mid+1, e, i, j, val);
    
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}


void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    init(1, 0, n-1);

    int x,y,type,val;
    //query 
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>x>>y;
            printf("sum(%d,%d)=%d\n",x,y,query(1,0,n-1,x-1,y-1));
        }
        else{
            cin>>x>>y>>val;
            update(1,0,n-1,x-1,y-1, val);
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

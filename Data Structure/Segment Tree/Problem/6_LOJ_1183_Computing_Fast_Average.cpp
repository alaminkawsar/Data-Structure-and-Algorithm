#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

ll ar[sz+5];

struct info{
    ll prop=-1,sum=0;
}tree[sz*4+5];

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

ll query(int node,int b,int e, int i, int j, int carry=-1){
    if(j<b or i>e){
        return 0;
    }

    if(i<=b and e<=j){
        if(carry>-1) return 1LL*carry*(e-b+1);
        else return 1LL*tree[node].sum;
    }
    
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;
    if(carry==-1) carry=tree[node].prop;

    ll p1 = query(left, b, mid, i, j,carry);
    ll p2 = query(right, mid+1, e, i, j, carry);
    //printf("Tree %d=(%d,%d)->(%d %d %d)\n",node,b,e,tree[node].sum,tree[node].prop,carry);

    
    return p1+p2;
}

void update(int node,int b,int e, int i,int j, int val, int carry){
    if(j<b or i>e){
        if(carry>-1){
            tree[node].sum=1LL*carry*(e-b+1);
            tree[node].prop=1LL*carry;
        }
        //printf("Tree %d=(%d,%d)->(%lld %lld %d)\n",node,b,e,tree[node].sum,tree[node].prop,carry);

        return;
    }

    if(i<=b and e<=j){
        carry=val;
        tree[node].sum=carry*(e-b+1);
        tree[node].prop=carry;
        //printf("Tree %d=(%d,%d)->(%lld %lld %d)\n",node,b,e,tree[node].sum,tree[node].prop,carry);
        return;
    }
    
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;
    
    ll k = tree[node].prop;
    tree[node].prop=-1;
    if(carry>-1) k = carry;

    update(left, b, mid, i, j, val,k);
    update(right, mid+1, e, i, j, val, k);
    
    tree[node].sum = tree[left].sum + tree[right].sum;
    //printf("Tree %d=(%d,%d)->(%lld %lld %d)\n",node,b,e,tree[node].sum,tree[node].prop,carry);

}


void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        ar[i]=0;
    }
    int x,y,type,val;
    //query 
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==2){
            cin>>x>>y;
            ll ans = query(1,0,n-1,x,y);
            ll g = __gcd(ans,1LL*(y-x+1));
            //cout<<ans<<' '<<(y-x+1)<<endl;
            if((y-x+1)/g==1){
                printf("%lld\n",ans/g);
            }else printf("%lld/%lld\n",ans/g,(y-x+1)/g);
        }
        else{
            cin>>x>>y>>val;
            update(1,0,n-1,x,y, val, -1);
        }
    }
    memset(tree,0,sizeof(tree));

    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d:\n",++ts);
        solve();
    }
    return 0;
}

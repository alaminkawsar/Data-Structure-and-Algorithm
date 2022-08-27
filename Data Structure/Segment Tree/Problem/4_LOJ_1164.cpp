#include<bits/stdc++.h>
#define PII pair<int,long long>
#define pii pair<int,int>
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)
#define Px(x) cout << "check " << x <<endl;
#define Py(x,y) cout << "Check "<<x << " "<<y<<endl;
#define clr(a) memset(a,0,sizeof(a))
#define MAX 100005
using namespace std;

ll tree[MAX*4];
ll prop[MAX*4];
//int ar[MAX];

void update(int node,int b,int e,int i,int j,ll val){
    if (j<b || i>e) return;
    if (i<=b && e<=j){
        tree[node]=tree[node]+(ll)(e-b+1)*val;
        prop[node]+=val;
        return;
    }
    int left=node<<1;
    int right=left+1;
    //Py(left,right);
    int mid=(b+e)>>1;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right]+(ll)(e-b+1)*prop[node];
}
ll query(int node,int b,int e,int i,int j,ll carry=0){
    if (j<b || i>e) return 0;
    if (i<=b && e<=j){
        return tree[node]+carry*(ll)(e-b+1);
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    ll p=query(left,b,mid,i,j,(carry+prop[node]));
    ll q=query(right,mid+1,e,i,j,(carry+prop[node]));
    return p+q;

}

int main(){
    int test,t=0;
    //freopen("tx.txt","r",stdin);
    cin>>test;
    while(test--){
        int n,q;
        scanf("%d%d",&n,&q);
        //rep(int i,n) scanf("%d",&ar[i]);
        printf("Case %d:\n",++t);
        while(q--){
            int choose;
            scanf("%d",&choose);
            if (choose==0){
                int i,j;
                ll val;
                scanf("%d%d%lld",&i,&j,&val);
                update(1,0,n-1,i,j,val);
            }
            else{
                int i,j;
                scanf("%d%d",&i,&j);
                ll ans=query(1,0,n-1,i,j);
                printf("%lld\n",ans);
            }
        }
        clr(tree);
        clr(prop);
    }


}

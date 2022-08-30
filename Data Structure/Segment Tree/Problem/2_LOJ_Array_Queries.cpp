#include<bits/stdc++.h>
#define MAX 100005
#define inf 1000000000
#define clr(a) memset(a,0,sizeof(a))
using namespace std;

int tree[MAX*3];
int ar[MAX];
void init(int node,int b,int e){
    if (b==e){
        tree[node]=ar[b];
    }
    else{
        int mid=(b+e)/2;
        int left=2*node;
        int right=left+1;
        init(left,b,mid);
        init(right,mid+1,e);
        tree[node]=min(tree[left],tree[right]);
    }
}
int query(int node,int b,int e,int i,int j){
    if (i>e || j<b) return inf;
    if (i<=b && e<=j) return tree[node];
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
    return min(p,q);
}
int main()
{
    //freopen("inp.txt","r",stdin);
    int test,t=0;
    cin>>test;
    while(test--){
        int n,q;
        scanf("%d%d",&n,&q);
        for (int i=1;i<=n;i++){
            scanf("%d",&ar[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",++t);
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            int f=query(1,1,n,a,b);
            printf("%d\n",f);
        }
        clr(ar);
        clr(tree);
    }
}

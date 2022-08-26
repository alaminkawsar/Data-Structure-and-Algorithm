#include<bits/stdc++.h>
#define MAX (int)(4e5+5)
#define PB push_back
#define MP make_pair
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(a) (int)a.size()
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define p1(a) cout<<"Check "<<a<<endl
#define p2(a,b) cout<<"Check "<<a<<' '<<b<<endl
#define p3(a,b,c) cout<<"Check "<<a<<' '<<b<<' '<<c<<endl
#define forn(i,n) for(int i=0;i<int(n);i++)
#define fore(i,l,n) for(int i=int(l);i<int(n);i++)
#define clr(a) memset(a,0,sizeof(a))
#define MOD (int)(1e7+7)
#define INF (long long)(1e18)

using namespace std;

int tree[MAX];
int ar[MAX];

//Segment_Tree_without_Lazy_Propagation
void init(int node,int b,int e){
    if(b==e){
        tree[node]=ar[b];
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void update(int node,int b,int e,int indx,int val){
    if(indx<b || e<indx) return;
    if(b==e && b==indx){
        tree[node]+=val;
        ar[b]+=val;
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,b,mid,indx,val);
    update(right,mid+1,e,indx,val);
    tree[node]=tree[left]+tree[right];
}
int quiry(int node,int b,int e,int i,int j){
    if (i>e || j<b) return 0;
    if (i<=b && e<=j) return tree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    int p=quiry(left,b,mid,i,j);
    int q=quiry(right,mid+1,e,i,j);
    return p+q;
}
int main(){
    int test=1,t=0;
    si(test);
    while(test--){
        int n,q;
        sii(n,q);
        forn(i,n) si(ar[i]);
        init(1,0,n-1);
        printf("Case %d:\n",++t);
        while(q--){
            int type,val,indx;
            si(type);
            if(type==1){
                si(indx);
                printf("%d\n",ar[indx]);
                update(1,0,n-1,indx,-ar[indx]);
            }else if(type==2){
                sii(indx,val);
                update(1,0,n-1,indx,val);
            }else{
                sii(indx,val);
                printf("%d\n",quiry(1,0,n-1,indx,val));
            }
        }
        clr(tree);
        clr(ar);
    }
    return 0;
}


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
int const sz=(int)4e5+5;

int ar[sz+5];

struct info{
    int rep,dif=1;
    vector<int>vec;
}tree[sz*3+5];

vector<int>Merge(vector<int>&a,vector<int>&b){
    vector<int>c;
    c.resize(a.size()+b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    return c;
}


void init(int node, int b, int e){
    if(b==e){
        tree[node].vec.push_back(ar[b]);
        return;
    }
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    init(left,b, mid);
    init(right, mid+1, e);
    
    tree[node].vec=Merge(tree[left].vec,tree[right].vec);
    int unique=1;
    for(int i=1;i<tree[node].vec.size();i++){
        if(tree[node].vec[i-1]!=tree[node].vec[i]) unique++;
    }
    tree[node].dif=unique;
}

int query(int node, int b, int e,int i,int j){
    if(j<b or e<i) return 0;
    if(i<=b and e<=j){
        return tree[node].dif;
    }
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    return query(left,b, mid,i,j)+query(right,mid+1,e, i, j);
}

void print(int node, int b, int e){
    if(b==e){
        printf("%d\n",tree[node].vec[0]);
        return;
    }

    //print them
    printf("range(%d,%d), Number=%d\n",b,e,tree[node].dif);
    for(int i=0;i<tree[node].vec.size();i++){
        printf("%d",tree[node].vec[i]);
    }
    cout<<endl;
    int mid=(b+e)/2;
    int left = node*2;
    int right = left+1;

    print(left,b, mid);
    print(right, mid+1, e);
    
}


void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    
    init(1, 0, n-1);
    //print(1,0,n-1);
    int l,r;
    while(q--){
        read(l);
        read(r);
        printf("%d\n",query(1,0,n-1,l-1,r-1));
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

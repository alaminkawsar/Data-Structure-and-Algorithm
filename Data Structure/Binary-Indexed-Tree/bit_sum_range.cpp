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

class BIT {
    public:
    vector<int>tree;
    int siz;
    
    BIT(int s){
        tree.resize(s+5,0);
        siz=s;
    }

    void update(int id,int val){
        while(id<=siz){
            tree[id]+=val;
            id+=(id&-id);
        }
    }

    int get(int id){
        int sum=0;
        while(id>0){
            sum+=tree[id];
            id-=(id&-id);
        }
        return sum;
    }
};

void solve()
{
    vector<int>ar{1,2,3,4,5};
    int n = ar.size();

    BIT tr(n);

    for(int i=0;i<n;i++){
        tr.update(i+1,ar[i]);
    }
    // get sum range 2 4
    for(int i=0;i<n;i++){
        cout<<tr.get(i+1)<<endl;
    }
    cout<<tr.get(5)-tr.get(3)<<endl;

    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

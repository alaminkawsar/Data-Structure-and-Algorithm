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

void solve()
{
    int n,q; read(n);read(q);
    int ar[n+5];
    vector<int>csum(n+5,0),repeat(sz,0);
    csum[0]=0;
    for(int i=0;i<n;i++){
        read(ar[i]);
        if(i==0){
            csum[i+1]=1;
            repeat[ar[i]]++;
            continue;
        }
        csum[i+1]=csum[i];
        if(repeat[ar[i]]==0) csum[i+1]++;
        repeat[ar[i]]++;
    }
    int l, r;
    while(q--){
        read(l);
        read(r);
        int k = r-l+1;

        int ans = csum[r]-csum[l-1];
        if(k<=ans) ans--;
        else ans++;
        printf("%d\n",ans);
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

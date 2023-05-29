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
int const sz=(int)2e6+5;

vector<int>dp;

int minimum(int n){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];

    int m = n;
    set<int>dig;
    while(m){
        if(m%10>0) dig.insert(m%10);
        m/=10;
    }
    int k = INT_MAX;
    for(auto it: dig){
        if(n-it<0) continue; 
        int mn = minimum(n-it);
        k = min(mn,k);
    }
    return dp[n]=k+1;
}

void solve()
{
    int n; cin>>n;
    dp.resize(n+5,-1);
    dp[0]=0;
    int ans = minimum(n);
    cout<<ans<<endl;
    
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

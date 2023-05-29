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
#define inf 1000000007

using namespace std;
int const sz=(int)2e8+5;

int dp[501][501];

int get(int n,int m){
    //cout<<dp[n][m]<<endl;

    if(n>m) swap(n,m);
    if(dp[n][m]!=sz) return dp[n][m];

    if(n==m) return dp[n][m]=0;
    if(n==1 or m==1) return dp[n][m]=(n==1?m-1:n-1);

    for(int i=1;i<n;i++){
        dp[n][m]=min(dp[n][m],get(i,m)+get(n-i,m)+1);
    }
    for(int i=1;i<m;i++){
        dp[n][m]=min(dp[n][m],get(n,i)+get(n,m-i)+1);
    }
    return dp[n][m];

}

void solve()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<=500;i++) for(int j=0;j<=500;j++) dp[i][j]=sz;
    cout<<get(n,m)<<endl;
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

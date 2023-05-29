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
int const sz=(int)1e6+5;

int dice[]={1,2,3,4,5,6};
int dp[6][sz];
int ans=0;

int fun(int j,int n){
    if(n<0) return 0;
    if(n==0){
        return dp[j][n]=1;
    }
    if(dp[j][n]>=0) return dp[j][n];
    dp[j][n]=0;
    for(int i=0;i<6;i++){
        dp[j][n]+=fun(i,n-dice[i]);
        dp[j][n]%=MOD;
    }
    return dp[j][n]%MOD;

}

void solve()
{
    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    
    ans = fun(0,n);
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

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
int const sz=(int)5e3+5;

int n;
vector<int>v;
int dp[sz][sz][2];
int sum=0;

int get(int i,int j,int person=0){
    if(i>j) return 0;

    if(dp[i][j][person]>-1) return dp[i][j][person];

    dp[i][j][person]=max(get(i+1,j,person^1)+v[i],get(i,j-1,person^1)+v[j]);
    

    //cout<<dp[i][j]<<endl;

    return dp[i][j][person];
}

void solve()
{
    cin>>n;
    v.resize(n+1);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++)  dp[i][j][0]=-1,dp[i][j][1]=-1;
    int ans = get(0,n-1);
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

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
string s,st;

int dp[sz][sz];

int get(int i,int j){
    if(i<=0) return dp[i][j]=j;
    if(j<=0) return dp[i][j]=i;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i-1]==st[j-1]){
        return dp[i][j]=get(i-1,j-1);
    }

    int x = get(i-1,j);
    int y = get(i,j-1);
    int z = get(i-1,j-1);
    dp[i][j]=min({x,y,z})+1;
    return dp[i][j];
}

void solve()
{
    cin>>s;
    cin>>st;

    int n = s.size();
    int m = st.size();
    memset(dp,-1,sizeof(dp));
    int ans = get(n,m);
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

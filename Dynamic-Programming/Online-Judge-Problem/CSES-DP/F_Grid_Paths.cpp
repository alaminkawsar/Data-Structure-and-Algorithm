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
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    if(s[0][0]=='*'){
        cout<<0<<endl;
        return;
    }
    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='*' or dp[i][j]==0) continue;
            if(j+1<n and s[i][j+1]=='.') dp[i][j+1]+=dp[i][j]%MOD;
            if(i+1<n and s[i+1][j]=='.') dp[i+1][j]+=dp[i][j]%MOD;
        }
    }
    cout<<dp[n-1][n-1]%MOD<<endl;
    
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

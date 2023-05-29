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

vector<int>coin;
vector<int>dp;
int n,sum;

int inf=10000000;


void solve()
{
    cin>>n>>sum;

    coin.resize(n);
    dp.resize(sum+1,0);

    dp[0]=1;

    for(int i=0;i<n;i++) cin>>coin[i];
    sort(coin.begin(),coin.end());
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j-coin[i]>=0 and dp[j-coin[i]]>0){
                dp[j]+=dp[j-coin[i]];
                dp[j]%=MOD;
            }
        }
    }
    cout<<dp[sum]<<endl;

    
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

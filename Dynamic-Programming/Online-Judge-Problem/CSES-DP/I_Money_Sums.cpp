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
int const sz=(int)1e5+5;

void solve()
{
    int n; cin>>n;
    vector<int>coin(n);
    for(int i=0;i<n;i++) cin>>coin[i];
    bool dp[sz];
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    sort(coin.begin(),coin.end());
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=sz-coin[i];j>=0;j--){
            if(dp[j]){
                dp[j+coin[i]]=true;
                //cout<<j<<' '<<coin[i]<<endl;;
            }
        }
    }

    for(int i=1;i<=sz;i++){
        if(dp[i])ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
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

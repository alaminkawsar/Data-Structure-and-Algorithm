//print all the permutation for a given string

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

map<string,int>has;

void printPermuation(string s,int l, int r){
    if(l>=r){
        if(has.count(s)) return;
        cout<<s<<endl;
        has[s]++;
        return;
    }
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        printPermuation(s,l+1,r);
        swap(s[i],s[l]);
    }
}

void solve()
{
    string  str = "AABC";
    printPermuation(str,0,str.size()-1);

    
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

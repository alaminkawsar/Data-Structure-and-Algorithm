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
int const sz=(int)4e5+5;

int parent[sz+5];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}


void solve()
{
    int m; cin>>m;
    string s; cin>>s;
    int n = s.size();

    for(int i=0;i<=n;i++) make_set(i);

    stack<int>st;

    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        else{
            //printf("%d ",i);
            union_sets(i,st.top());
            st.pop();
        }
        if(i+1<n and s[i]==')' and s[i+1]=='('){
            union_sets(i,i+1);
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(parent[i]==i) cnt++;
    }
    cout<<cnt<<endl;
    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
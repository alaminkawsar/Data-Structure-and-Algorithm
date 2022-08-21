//the task is offline. We will at first disjoint the connected componants from first to last.
// Then we iterate query from last to first and join set which we disjoint
// This blog describe awesome solution. solution link: http://en.shafaetsplanet.com/problem-solving-consecutive-letters-mist-inter-university-contest-2019/

#include<bits/stdc++.h>
#define clr(ar) memset(ar,0,sizeof(ar))
using namespace std;
typedef long long ll;
const int sz = (int) 2e5+20;


int parent[sz+5],size[sz], ans[sz];
int k=1;

void make_set(int v) {
    parent[v] = v;
    size[v]=1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        parent[b]=a;
        size[a]+=size[b];
    }
}

void solve(){

    pair<int,int>query[sz];
    int n , q;
    char s[sz], save[sz];
    scanf("%s",s);
    strcpy(save,s);
    n = strlen(s);
    scanf("%d",&q);

    for(int i=0;i<q;i++){
        scanf("%d%d",&query[i].first,&query[i].second);
        if(query[i].first==2)
            s[query[i].second]='#';
    }
    
    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
        //printf("block = %d\n",block[i]);
        if(i>=1 and s[i]!='#' and s[i-1]==s[i]){
            union_sets(i,i-1);
        }
    }
    // for(int i=0;i<q;i++){
    //     printf("i= %d %d\n",query[i].type,query[i].index);
    // }
    // for(int i=0;i<n;i++){
    //     printf("i= %d %d\n",i,size[i]);
    // }
    vector<int>ans;
    for(int i=q-1;i>=0;i--){
        if(query[i].first==1){
            ans.push_back(size[find_set(query[i].second)]);
        }else{
            s[query[i].second] = save[query[i].second];
            if(query[i].second>=1 and s[query[i].second]==s[query[i].second-1]){
                union_sets(query[i].second,query[i].second-1);
            }
            if(query[i].second<n-1 and s[query[i].second]==s[query[i].second+1]){
                union_sets(query[i].second,query[i].second+1);
            }
            // ans.push_back(size[find_set(x)]);
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        printf("%d\n",ans[i]);
    }
    

    
}

int main()
{
    
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        printf("Case %d:\n",++ts);

        solve();
    }
    return 0;
}


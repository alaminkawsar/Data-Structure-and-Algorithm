#include<bits/stdc++.h>
#define MAX 100005
#define clr(a) memset(a,0,sizeof(a))
using namespace std;

int prop[MAX*4];

void update(int node,int b,int e,int i,int j){
    if (i>e || j<b) return;
    if (i<=b && e<=j){
        prop[node]+=1;
        //cout << "HI "<<b<<' '<<e<<' '<<node<<' '<<prop[node]<<endl;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}


int query(int node,int b,int e,int i,int j,int carry){
    if(i>e || j<b) return 0;
    if (i<=b && e<=j){
            //cout << "HI "<<b<<' '<<e<<' '<<node<<' '<<prop[node]+carry<<endl;
        return prop[node]+carry;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p=query(left,b,mid,i,j,carry+prop[node]);
    int q=query(right,mid+1,e,i,j,carry+prop[node]);
    return p+q;


}
int main()
{
    //freopen("input.txt","r",stdin);
    int test,t=0;
    cin>>test;
    while(test--){
        char s[MAX*2];
        scanf("%s",s);
        int n=strlen(s);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++t);
        while(q--){
            char ch[2];
            scanf("%s",ch);
            if(ch[0]=='I'){
                //update part
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,1,n,x,y);
            }
            else{
                int x;
                scanf("%d",&x);
                //cout << x << endl;
                int ans=query(1,1,n,x,x,0);
                //cout << ans<<endl;
                if (ans%2==0) printf("%c\n",s[x-1]);
                else{
                    if (s[x-1]=='0') printf("1\n");
                    else printf("0\n");
                }
            }

        }
        clr(prop);
    }
}

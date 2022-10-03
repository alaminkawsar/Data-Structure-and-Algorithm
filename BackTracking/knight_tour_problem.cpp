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

int fx[]={2, 1, -1, -2, -2, -1, 1, 2};
int fy[]={ 1, 2, 2, 1, -1, -2, -2, -1 };

using namespace std;
int const sz=(int)2e5+5;

int cell[1000][1000];
int row, col;

bool check(int x,int y){
    if(x>=0 and y>=0 and x<row and y<col and cell[x][y]==-1) return true;
    return false;
}

int solveKnightTour(int x,int y,int move){
    if(row*col==move) return 1;
    for(int i=0;i<8;i++){
        int nextX = x+fx[i];
        int nextY = y+fy[i];
        if(check(nextX, nextY)){
            cell[nextX][nextY]=move;
            if(solveKnightTour(nextX,nextY,move+1))
                return 1;
            else
                cell[nextX][nextY]=-1;
        }
    }
    return 0;
}

void solve()
{
    row=8,col=8;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cell[i][j]=-1;

    cell[0][0]=0;
    int ans = solveKnightTour(0,0,1);

    if(ans){
        //print all the cell
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                printf("%d ",cell[i][j]);

            }
            printf("\n");
        }
    }
    else printf("No Solution Exist\n");
    
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

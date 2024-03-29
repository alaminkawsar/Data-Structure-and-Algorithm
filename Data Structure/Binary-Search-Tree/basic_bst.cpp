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

struct node {
    node *left, *right;
    int item;
    node(int val){
        left=NULL;
        right = NULL;
        item = val;
    }
};


node* start;

class BST{
    public:
    node* start;

    BST(){
        start=nullptr;
    }

    void insert(int key){
        if(start==NULL){
            start = new node(key);
            return;
        }
        node *curr=start, *par;
        while(curr!=NULL){
            par = curr;
            if(curr->item<key){
                curr = curr->right;
            }else curr = curr->left;
        }
        node *newnode = new node(key);
        if(par->item<key){
            par->right = newnode;
        }else par->left = newnode;
    }

    void inOrder(node* curr){
        if(curr==NULL){
            return;
        }
        inOrder(curr->left);
        printf("%d ",curr->item);
        inOrder(curr->right);
    }

    void preOrder(node* curr){
        if(curr==NULL){
            return;
        }
        printf("%d ",curr->item);
        preOrder(curr->left);
        preOrder(curr->right);
    }

    void postOrder(node* curr){
        if(curr==NULL){
            return;
        }
        postOrder(curr->left);
        postOrder(curr->right);
        printf("%d ",curr->item);
    }
};
void solve()
{
    //make insert operation
    BST bst;
    
    vector<int>ar{20,30,10,15,5};
    for(auto x: ar){
        bst.insert(x);
    }

    printf("Pre Ordered Valeus: ");
    bst.preOrder(bst.start);
    printf("\n");

    printf("In Ordered Valeus: ");
    bst.inOrder(bst.start);
    printf("\n");

    printf("Post Ordered Valeus: ");
    bst.postOrder(bst.start);
    printf("\n");

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

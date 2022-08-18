#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

struct Student
{
    int roll;
    string name;
    struct Student *next;
};

void add(struct Student *head_ref, int roll, string name){
    /*1. Allocate node */
    Student *new_node = new Node();
    Student *new_node = (struct Student*) malloc(sizeof(struct Student));

    /*2. put in the data*/
    new_node->roll = roll;
    new_node->name = name;
    new_node->next = NULL;

    if(start==NULL){
        start = new_node;
        return;
    }

}

Student *start=NULL;

void solve()
{
    int roll;
    string name;
    cin>>roll>name;
    push

    
}
int main()
{
    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdin);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

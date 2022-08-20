//This is built in double ended queue, just show some properties of double ended queue

#include<bits/stdc++.h>
using namespace  std;

void showdq(deque<int>g){
    for (auto it = g.begin(); it!=g.end(); ++it){
        cout<<'\t'<<*it;
    }
    cout<<'\n';
}

int main(){
    deque<int>dq;
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);
    dq.push_front(1);

    cout<<"The deque from first to last:";
    showdq(dq);
}

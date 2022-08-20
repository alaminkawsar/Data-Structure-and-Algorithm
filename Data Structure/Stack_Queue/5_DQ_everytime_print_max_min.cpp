/*Given an array of size n.*/

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
    int n = 10, m=3;

    vector<int>ar = {2,1, 3, 4 ,5 ,6, 8, 10, 1, 5};
    for(int i=0;i<n;i++){
        if(i==0){
            dq.push_back(ar[i]);
            continue;
        }else{
            if(i%m==0){
                cout<<dq.back()<<" ";
                dq.pop_back();
                dq.push_back(ar[i]);
            }else{
                if(ar[i]<dq.back()){
                    dq.pop_back();
                    dq.push_back(ar[i]);
                }
            }
        }
    }
    if(n%m!=0){
        cout<<dq.back()<<endl;
    }


}

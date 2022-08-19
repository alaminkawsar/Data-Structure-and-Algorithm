/*Cycle detection using floyed cycle finding algorithm*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

//Definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
}


ListNode* Solution::detectCycle(ListNode* A){
    if(!A->next) return NULL;

    ListNode *tortoise = A;
    ListNode *hare = A;

    while(hare){
        if(hare->next and hare->next->next)
            hare=hare->next->next;
        else
            return NULL; //no cycle
        
        tortoise = tortoise->next;
        if(hare==tortoise) break; //cycle exist

    }
    ListNode *tortoise2 = A;
    while(tortoise2 != tortoise){
        tortoise = tortoise->next;
        tortoise2 = tortoise->next;
    }
    return tortoise;
    
}
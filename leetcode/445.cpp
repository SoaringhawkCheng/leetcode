//
//  445.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/9.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        int carrybit=0;
        while(l1){
            stk1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            stk2.push(l2->val);
            l2=l2->next;
        }
        ListNode dump(-1);
        while(!stk1.empty()||!stk2.empty()){
            int lhs=0,rhs=0;
            if(!stk1.empty()){
                lhs=stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                rhs=stk2.top();
                stk2.pop();
            }
            int sum=lhs+rhs+carrybit;
            carrybit=sum/10;
            ListNode *tmp=new ListNode(sum%10);
            tmp->next=dump.next;
            dump.next=tmp;
        }
        if(carrybit) {
            ListNode *tmp=new ListNode(carrybit);
            tmp->next=dump.next;
            dump.next=tmp;
        }
        return dump.next;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}

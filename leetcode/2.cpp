
//
//  2.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/21.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *pos=&dummy;
        int carrybit=0;
        while(l1||l2){
            int lhs=0,rhs=0;
            if(l1) {lhs=l1->val;l1=l1->next;}
            if(l2) {rhs=l2->val;l2=l2->next;}
            int sum=lhs+rhs+carrybit;
            carrybit=sum/10;
            sum=sum%10;
            pos->next=new ListNode(sum);
            pos=pos->next;
        }
        if(carrybit)
            pos->next=new ListNode(carrybit);
        return dummy.next;
    }
};

int main(int argc,const char *argv[]){
    
}

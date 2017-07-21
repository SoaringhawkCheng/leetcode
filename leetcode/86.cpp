//
//  86.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/21.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lt(-1);
        ListNode ge(-1);
        ListNode *plt=&lt;
        ListNode *pge=&ge;
        while(head){
            if(head->val<x){
                plt->next=head;
                plt=plt->next;
            }
            else{
                pge->next=head;
                pge=pge->next;
            }
            head=head->next;
        }
        plt->next=ge.next;
        pge->next=NULL;
        return lt.next;
    }
};

int main(int argc,const char *argv[]){
    
}

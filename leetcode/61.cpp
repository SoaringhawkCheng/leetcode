//
//  61.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/22.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0) return head;
        ListNode *prev=head;
        int len=1;
        while(prev->next){
            ++len;
            prev=prev->next;
        }
        k=len-k%len;
        prev->next=head;
        for(int i=0;i<k;++i){
            prev=head;
            head=head->next;
        }
        prev=NULL;
        return head;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}

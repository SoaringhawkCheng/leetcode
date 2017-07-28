//
//  82.cpp
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        int curval=head->val+1;
        ListNode dummy(curval);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *cur=head;
        bool duplicate=false;
        while(cur){
            while(cur->next&&cur->val==cur->next->val){
                duplicate=true;
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
            }
            if(duplicate){
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
                duplicate=false;
            }
            else{
                prev->next=cur;
                prev=cur;
                cur=cur->next;
            }
        }
        prev->next=cur;
        return dummy.next;
    }
};

int main(int argc,const char *argv[]){
    
    return 0;
}

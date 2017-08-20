//
//  25.cpp
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
 
class Solution1 {//递归
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        ListNode *newhead=head;
        int i;
        for(i=0;i<k;++i){
            if(newhead==NULL) break;
            newhead=newhead->next;
        }
        if(i==k){
            ListNode dummy(-1);
            ListNode *curr=head;
            while(curr!=newhead){
                ListNode *tmp=curr;
                curr=curr->next;
                tmp->next=dummy.next;
                dummy.next=tmp;
            }
            head->next=reverseKGroup(newhead, k);
            head=dummy.next;
        }
        return head;
    }
};

class Solution2 {//迭代
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *curr=head,*tail=NULL;
        int num=0;
        while(curr){
            ++num;
            curr=curr->next;
        }
        while(num>=k){
            tail=prev->next;
            curr=tail->next;
            for(int i=1;i<k;++i){
                tail->next=curr->next;
                curr->next=prev->next;
                prev->next=curr;
                curr=tail->next;
            }
            prev=tail;
            num=num-k;
        }
        return dummy.next;
    }
};

int main(int argc,const char *argv[]){
    ListNode list[]={0,1,2,3,4,5,6};
    list[0].next=&list[1];
    list[1].next=&list[2];
    list[2].next=&list[3];
    list[3].next=&list[4];
    list[4].next=&list[5];
    list[5].next=&list[6];
    Solution s;
    ListNode *head=s.reverseKGroup(list, 3);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}

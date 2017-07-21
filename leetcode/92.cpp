//
//  92.cpp
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

class Solution {//书上的方法
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        for(int i=1;i<m;++i)
            prev=prev->next;
        ListNode *head2=prev;
        prev=head2->next;
        ListNode *cur=prev->next;
        for(int i=m;i<n;++i){
            prev->next=cur->next;
            cur->next=head2->next;
            head2->next=cur;
            cur=prev->next;
        }
        return dummy.next;
    }
};

class Solution1{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *cur=head;
        for(int i=1;i<m;++i){
            prev=cur;
            cur=cur->next;
        }
        ListNode *head2=prev;
        prev=cur;
        cur=cur->next;
        for(int i=m;i<n;++i){
            prev->next=cur->next;
            cur->next=head2->next;
            head2->next=cur;
            cur=prev->next;
        }
        return dummy.next;
    }
};

int main(int argc,const char *argv[]){
//    vector<ListNode> list={1,2,3,4,5};
//    list[0].next=&list[1];
//    list[1].next=&list[2];
//    list[2].next=&list[3];
//    list[3].next=&list[4];
    vector<ListNode> list={3,5};
    list[0].next=&list[1];
    ListNode *plist=&list[0];
    Solution1 s;
    plist=s.reverseBetween(plist, 1, 2);
    while(plist){
        cout<<plist->val<<" ";
        plist=plist->next;
    }
    cout<<endl;
    return 0;
}
